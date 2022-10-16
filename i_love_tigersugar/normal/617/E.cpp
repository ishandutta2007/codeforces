#include<bits/stdc++.h>
#define MAXN   100100
#define MAXV   1500150
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
class FenwickTree {
    private:
    vector<int> v;
    int n;
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x) {
        for (;x<=n;x+=x&-x) v[x]++;
    }
    int get(int l,int r) const {
        return (l==1?get(r):get(r)-get(l-1));
    }
};
class SegmentTree {
    private:
    vector<long long> tree;
    vector<int> lazy;
    int n;
    void pushDown(int i,int l,int r) {
        int m=(l+r)>>1;
        tree[2*i]+=1LL*lazy[i]*(m-l+1);
        tree[2*i+1]+=1LL*lazy[i]*(r-m);
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
    }
    void update(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i]+=r-l+1;
            lazy[i]++;
            return;
        }
        int m=(l+r)>>1;
        pushDown(i,l,r);
        update(2*i,l,m,u,v);
        update(2*i+1,m+1,r,u,v);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    long long get(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return (0);
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        pushDown(i,l,r);
        long long L=get(2*i,l,m,u,v);
        long long R=get(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,0);
        lazy.assign(4*n+7,0);
    }
    void update(int l,int r) {
        update(1,1,n,l,r);
    }
    long long get(int l,int r) {
        return (get(1,1,n,l,r));
    }
};
struct Query {
    int l,r,id;
    Query() {
        l=r=id=0;
    }
    Query(int _l,int _r,int _id) {
        l=_l;r=_r;id=_id;
    }
    bool operator < (const Query &q) const {
        return (l>q.l);
    }
};
const int bigSize=333;
Query query[MAXN];
int n,q,xorReq,a[MAXN],s[MAXN];
vector<int> pos[MAXV],bigGroup;
long long answer[MAXN];
FenwickTree bit;
SegmentTree myit[MAXV];
void init(void) {
    scanf("%d%d%d",&n,&q,&xorReq);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        query[i]=Query(l,r,i);
    }
}
void prepare(void) {
    FOR(i,1,n) s[i]=s[i-1]^a[i];
    FOR(i,1,n) pos[s[i]].push_back(i);
    REP(i,MAXV) if (pos[i].size()>bigSize) bigGroup.push_back(i);
    sort(query+1,query+q+1);
    bit=FenwickTree(n);
    FORE(it,bigGroup) myit[*it]=SegmentTree(pos[*it].size());
}
void update(int x,int id) {
    if (pos[x].size()>bigSize) {
        int t=lower_bound(ALL(pos[x]),id)-pos[x].begin()+1;
        myit[x].update(t,pos[x].size());
    } else FORE(it,pos[x]) if (*it>=id) bit.update(*it);
}
long long getAnswer(int l,int r) {
    long long res=bit.get(l,r);
    FORE(it,bigGroup) {
        int t=upper_bound(ALL(pos[*it]),r)-pos[*it].begin();
        res+=myit[*it].get(1,t);
    }
    return (res);
}
void process(void) {
    int j=n;
    FOR(i,1,q) {
        while (j>=query[i].l) {
            update(s[j-1]^xorReq,j);
            j--;
        }
        answer[query[i].id]=getAnswer(query[i].l,query[i].r);
    }
    FOR(i,1,q) cout<<answer[i]<<"\n";
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}