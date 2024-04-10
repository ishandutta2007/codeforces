#include<bits/stdc++.h>
#define MAX   400400
#define LIM   100
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
const int mod=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int inv[MAX];
int inverseValue(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void precount(void) {
    FOR(i,1,MAX-1) inv[i]=inverseValue(i);
}
int inverse(int x) {
    return (x<MAX?inv[x]:inverseValue(x));
}
class FenwickTree {
    vector<int> v;
    int n;
    void updateAdd(int x,int d) {
        assert(x>0);
        for (;x<=n;x+=x&-x) v[x]=(v[x]+d)%mod;
    }
    int getAdd(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res=(res+v[x])%mod;
        return (res);
    }
    void updateMul(int x,int d) {
        assert(x>0);
        for (;x<=n;x+=x&-x) v[x]=1LL*v[x]*d%mod;
    }
    int getMul(int x) const {
        int res=1;
        for (;x>=1;x&=x-1) res=1LL*res*v[x]%mod;
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n,int init) {
        this->n=n;
        v.assign(n+7,init);
    }
    void update(int x,int d) {
        updateAdd(x,d);
    }
    void updateRange(int l,int r,int d) {
        updateMul(l,d);
        if (r<n) updateMul(r+1,inverse(d));
    }
    int get(int x) const {
        return (getMul(x));
    }
    int getRange(int l,int r) const {
        return (l==1?getAdd(r):(getAdd(r)-getAdd(l-1)+mod)%mod);
    }
};
class SegmentTree {
    private:
    vector<int> tree,lazy;
    int n;
    void pushdown(int i) {
        FOR(j,2*i,2*i+1) {
            tree[j]=1LL*tree[j]*lazy[i]%mod;
            lazy[j]=1LL*lazy[j]*lazy[i]%mod;
        }
        lazy[i]=1;
    }
    void updateAdd(int i,int l,int r,int x,int v) {
        if (l==r) {
            tree[i]=(tree[i]+v)%mod;
            return;
        }
        pushdown(i);
        int m=(l+r)>>1;
        if (x>m) updateAdd(2*i+1,m+1,r,x,v);
        else updateAdd(2*i,l,m,x,v);
        tree[i]=(tree[2*i]+tree[2*i+1])%mod;
    }
    int getSum(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return (0);
        if (u<=l && r<=v) return (tree[i]);
        pushdown(i);
        int m=(l+r)>>1;
        int L=getSum(2*i,l,m,u,v);
        int R=getSum(2*i+1,m+1,r,u,v);
        return ((L+R)%mod);
    }
    void updateMul(int i,int l,int r,int u,int v,int x) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i]=1LL*tree[i]*x%mod;
            lazy[i]=1LL*lazy[i]*x%mod;
            return;
        }
        pushdown(i);
        int m=(l+r)>>1;
        updateMul(2*i,l,m,u,v,x);
        updateMul(2*i+1,m+1,r,u,v,x);
        tree[i]=(tree[2*i]+tree[2*i+1])%mod;
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,0);
        lazy.assign(4*n+7,1);
    }
    void updateMul(int l,int r,int v) {
        updateMul(1,1,n,l,r,v);
    }
    void updateAdd(int x,int v) {
        updateAdd(1,1,n,x,v);
    }
    int getSum(int l,int r) {
        return (getSum(1,1,n,l,r));
    }
};
struct Query {
    int type,par,child,val;
    Query() {
        type=par=child=val=0;
    }
    Query(int t,int p,int c,int v) {
        type=t;par=p;child=c;val=v;
    }
};
Query query[MAX];
vector<int> child[MAX];
int val[MAX],mul[MAX],sta[MAX],fin[MAX],par[MAX];
int n,q,cnt;
FenwickTree bitMul;
SegmentTree bitVal;
void init(void) {
    scanf("%d%d",&val[1],&q);
    n=1;
    FOR(i,1,q) {
        int type,node;
        scanf("%d%d",&type,&node);
        if (type==1) {
            int tmp;
            scanf("%d",&tmp);
            query[i]=Query(type,node,++n,tmp);
            par[n]=node;
            val[n]=tmp;
            child[node].push_back(n);
        } else query[i]=Query(type,node,-1,-1);
    }
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,child[u]) dfs(*it);
    fin[u]=cnt;
}
void prepare(void) {
    dfs(1);
    mul[1]=1;
    bitMul=FenwickTree(n,1);
    bitVal=SegmentTree(n);
    bitVal.updateAdd(sta[1],val[1]);
}
void addNode(int parent,int child) {
    //printf("Adding %d %d\n",parent,child);
    mul[parent]++;
    mul[child]=1;
    //printf("par %d %d\n",sta[parent],fin[parent]);
    //printf("child %d %d\n",sta[child],fin[child]);
    //printf("%d\n",1LL*mul[parent]*inverse(mul[parent]-1)%mod);
    bitMul.updateRange(sta[parent],fin[parent],1LL*mul[parent]*inverse(mul[parent]-1)%mod);
    bitVal.updateMul(sta[parent],fin[parent],1LL*mul[parent]*inverse(mul[parent]-1)%mod);
    bitVal.updateAdd(sta[child],1LL*val[child]*bitMul.get(sta[child])%mod);
}
int answer(int u) {
    int res=bitVal.getSum(sta[u],fin[u]);
    if (u!=1) res=1LL*res*inverse(bitMul.get(sta[par[u]]))%mod;
    return (res);
}
void process(void) {
    FOR(i,1,q) {
        if (query[i].type==1) addNode(query[i].par,query[i].child);
        else printf("%d\n",answer(query[i].par));
        /*printf("After %d\n",i);
        FOR(i,1,n) printf("%d ",bitMul.get(sta[i])); printf("\n");
        FOR(i,1,n) printf("%d ",bitVal.getSum(sta[i],sta[i])); printf("\n");*/
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    precount();
    init();
    prepare();
    process();
    return 0;
}