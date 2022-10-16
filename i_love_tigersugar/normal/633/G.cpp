#include<bits/stdc++.h>
#define MAX   100100
#define MAXM   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1ULL<<(i))
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
bool notPrime[MAXM];
int a[MAX];
vector<int> adj[MAX],prime;
int sta[MAX],fin[MAX],cnt,n,mod,q;
struct BitSet {
    static const int SIZE=1024;
    unsigned int val[32];
    int root;
    BitSet() {
        root=0;
        memset(val,0,sizeof val);
    }
    bool get(int x) const {
        x=(x+root)%mod;
        return (BIT(val[x>>5],x&31));
    }
    unsigned int getBlock(int L,int R) const {
        if (L>R) return (0);
        /*unsigned int res=0;
        FOR(i,L,R) res|=(1ULL*get(i))<<i;
        return (res);*/
        int oldL=L;
        int oldR=R;
        L=(L+root)%mod;
        R=(R+root)%mod;
        if (L<=R) {
            int id=L>>5;
            unsigned long long tmp=val[id]|((1ULL*val[id+1])<<32);
            tmp=tmp>>(L&31);
            return (tmp&(MASK(R-L+1)-1));
        } else {
            int left=mod-L;
            int right=R+1;
            return (getBlock(oldL,oldL+left-1)|(1ULL*getBlock(oldR-right+1,oldR)<<left));
        }
    }
    BitSet merge(const BitSet &x) const {
        BitSet res;
        /*REP(i,mod-1) if (get(i) || x.get(i))
            res.val[i>>5]|=MASK(i&31);
        return (res);*/
        REP(i,32) res.val[i]=getBlock(32*i,min(32*i+31,mod-1))|x.getBlock(32*i,min(32*i+31,mod-1));
        return (res);
    }
    void rotate(int x) {
        root=((root-x)%mod+mod)%mod;
    }
};
BitSet initBitSet(void) {
    BitSet res;
    res.val[0]=1;
    return (res);
}
class SegmentTree {
    private:
    vector<BitSet> tree;
    vector<int> lazy;
    int n;
    void pushDown(int i) {
        if (lazy[i]==0) return;
        FOR(j,2*i,2*i+1) {
            tree[j].rotate(lazy[i]);
            lazy[j]=(lazy[j]+lazy[i])%mod;
        }
        lazy[i]=0;
    }
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i].rotate(c);
            lazy[i]=(lazy[i]+c)%mod;
            return;
        }
        pushDown(i);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        tree[i]=tree[2*i].merge(tree[2*i+1]);
    }
    BitSet get(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return (BitSet());
        if (u<=l && r<=v) return (tree[i]);
        pushDown(i);
        int m=(l+r)>>1;
        BitSet L=get(2*i,l,m,u,v);
        BitSet R=get(2*i+1,m+1,r,u,v);
        return (L.merge(R));
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,initBitSet());
        lazy.assign(4*n+7,0);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c%mod);
    }
    BitSet get(int l,int r) {
        return (get(1,1,n,l,r));
    }
};
void loadTree(void) {
    scanf("%d%d",&n,&mod);
    FOR(i,1,n) scanf("%d",&a[i]);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u,int p) {
    sta[u]=++cnt;
    FORE(it,adj[u]) if (*it!=p) dfs(*it,u);
    fin[u]=cnt;
}
void prepare(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,mod-1) if (!notPrime[i]) {
        prime.push_back(i);
        for (int j=2*i;j<mod;j=j+i) notPrime[j]=true;
    }
    dfs(1,-1);
}
void process(void) {
    SegmentTree myit(n);
    FOR(i,1,n) myit.update(sta[i],sta[i],a[i]);
    scanf("%d",&q);
    REP(love,q) {
        int t,v;
        scanf("%d%d",&t,&v);
        if (t==1) {
            int x;
            scanf("%d",&x);
            myit.update(sta[v],fin[v],x);
        } else {
            BitSet tmp=myit.get(sta[v],fin[v]);
            int res=0;
            FORE(it,prime) if (tmp.get(*it)) res++;
            printf("%d\n",res);
        }
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    loadTree();
    prepare();
    process();
    return 0;
}