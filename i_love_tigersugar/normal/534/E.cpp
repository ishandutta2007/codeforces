#include<bits/stdc++.h>
#define MAX   800800
#define NMOD   3
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int pw[NMOD][MAX];
struct Hash {
    int len,val[NMOD];
    Hash() {
        len=0;
        memset(val,0,sizeof val);
    }
    Hash add(int x) const {
        Hash res;
        res.len=len+1;
        REP(i,NMOD) res.val[i]=(val[i]+1LL*x*pw[i][len])%mod[i];
        return (res);
    }
    Hash operator + (const Hash &x) const {
        Hash res;
        res.len=len+x.len;
        REP(i,NMOD) res.val[i]=(val[i]+1LL*x.val[i]*pw[i][len])%mod[i];
        return (res);
    }
    Hash operator * (int k) const {
        Hash res;
        res.len=len;
        REP(i,NMOD) res.val[i]=1LL*val[i]*k%mod[i];
        return (res);
    }
    bool operator == (const Hash &x) const {
        if (len!=x.len) return (false);
        REP(i,NMOD) if (val[i]!=x.val[i]) return (false);
        return (true);
    }
};
Hash simpleHash[MAX];
void precount(void) {
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,MAX-1) pw[j][i]=(1LL*pw[j][i-1]<<19)%mod[j];
    }
    FOR(i,1,MAX-1) simpleHash[i]=simpleHash[i-1].add(1);
}
struct SegmentTree {
    private:
    int n;
    vector<Hash> tree;
    void update(int i,int l,int r,int x,int v) {
        if (l==r) {
            int tmp=tree[i].len+v;
            tree[i]=simpleHash[tmp]*l;
            return;
        }
        int m=(l+r)>>1;
        if (x>m) update(2*i+1,m+1,r,x,v);
        else update(2*i,l,m,x,v);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,Hash());
    }
    void update(int x,int v) {
        update(1,1,n,x,v);
    }
    Hash getHash(void) const {
        return (tree[1]);
    }
};
int a[MAX],reqPath[MAX],n,m;
set<long long> distan;
Hash reqHash;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    REP(i,m) scanf("%d",&reqPath[i]);
    REP(i,m) reqHash=reqHash.add(reqPath[i]);
}
long long range(int x,int y) {
    return (max(0LL+a[x]-a[y],0LL+a[y]-a[x]));
}
void process(void) {
    int pos=1;
    int mode=1;
    vector<int> bigPath(1,pos);
    while (bigPath.size()<MAX) {
        if (pos+mode<1 || pos+mode>n) mode=-mode;
        pos+=mode;
        bigPath.push_back(pos);
    }
    long long curDistan=0;
    SegmentTree myit(n);
    REP(i,m) myit.update(bigPath[i],1);
    REP(i,m-1) curDistan+=range(bigPath[i],bigPath[i+1]);
    REP(i,2*n+7) {
        if (myit.getHash()==reqHash) distan.insert(curDistan);
        myit.update(bigPath[i],-1);
        myit.update(bigPath[i+m],1);
        curDistan-=range(bigPath[i],bigPath[i+1]);
        curDistan+=range(bigPath[i+m-1],bigPath[i+m]);
    }
    if (distan.size()!=1) cout<<-1<<endl; else cout<<*distan.begin()<<endl;
}
int main(void) {
    precount();
    init();
    process();
    return 0;
}