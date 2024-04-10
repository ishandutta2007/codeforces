#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
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
        if (x<1) return;
        for (;x<=n;x+=x&-x) v[x]++;
    }
    int get(int l,int r) const {
        return (l==1?get(r):get(r)-get(l-1));
    }
};
struct Query {
    int l,r,val,use;
    Query() {
        l=r=val=use=0;
    }
    Query(int _l,int _r,int _v,int _u) {
        l=_l;r=_r;val=_v;use=_u;
    }
    bool operator < (const Query &q) const {
        return (val<q.val);
    }
};
vector<Query> query;
int a[MAX],n,res[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void getQuery(int k) {
    int i=1;
    int L=2;
    int R=L+k-1;
    while (L<=n) {
        query.push_back(Query(L,min(R,n),a[i],k));
        i++;
        L+=k;
        R+=k;
    }
}
void process(void) {
    vector<pair<int,int> > seq;
    FOR(i,1,n) seq.push_back(make_pair(a[i],i));
    sort(ALL(seq));
    FOR(i,1,n-1) getQuery(i);
    sort(ALL(query));
    int id=0;
    FenwickTree bit(n);
    FORE(it,query) {
        while (id<seq.size() && seq[id].fi<it->val) {
            bit.update(seq[id].se);
            id++;
        }
        res[it->use]+=bit.get(it->l,it->r);
    }
    FOR(i,1,n-1) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}