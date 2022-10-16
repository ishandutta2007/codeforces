#include<bits/stdc++.h>
#define MAX   400400
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
class SegmentTree {
    private:
    int n;
    vector<int> tree;
    void assign(int i,int l,int r,int x,int v) {
        if (l==r) {
            tree[i]=v>n/2?-1:v;
            return;
        }
        int m=(l+r)>>1;
        if (x<=m) assign(2*i,l,m,x,v);
        else assign(2*i+1,m+1,r,x,v);
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }
    int getMaxLess(int i,int l,int r,int u,int v) const {
        if (l>v || r<u || l>r || v<u) return (-1);
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        int L=getMaxLess(2*i,l,m,u,v);
        int R=getMaxLess(2*i+1,m+1,r,u,v);
        return (max(L,R));
    }
    public:
    SegmentTree(int n=0) {
        this->n=n;
        tree.assign(4*n+7,0);
    }
    void assign(int x,int v) {
        assign(1,1,n,x,v);
    }
    int getMaxLess(int l,int r) const {
        return (getMaxLess(1,1,n,l,r));
    }
};
vector<int> adj[MAX];
int root,n,cnt;
int sta[MAX],fin[MAX],par[MAX],numChild[MAX];
int res[MAX];
SegmentTree myit;
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void rootDFS(int u) {
    numChild[u]=1;
    FORE(it,adj[u]) if (*it!=par[u]) {
        int v=*it;
        par[v]=u;
        rootDFS(v);
        numChild[u]+=numChild[v];
    }
}
bool isCentroid(int u) {
    if (n-numChild[u]>n/2) return (false);
    FORE(it,adj[u]) if (*it!=par[u] && numChild[*it]>n/2) return (false);
    return (true);
}
void prepareDFS(int u) {
    sta[u]=++cnt;
    numChild[u]=1;
    FORE(it,adj[u]) if (*it!=par[u]) {
        int v=*it;
        par[v]=u;
        prepareDFS(v);
        numChild[u]+=numChild[v];
    }
    fin[u]=cnt;
}
void calcDFS(int u) {
//    printf("AT %d\n",u);
//    FOR(i,1,n) printf("Value of %d is %d\n",i,myit.getMaxLess(sta[i],sta[i]));
    if (u==root) res[u]=1;
    else if (n-numChild[u]<=n/2) res[u]=1;
    else {
        int best=max(myit.getMaxLess(1,sta[u]-1),myit.getMaxLess(fin[u]+1,n));
//        printf("With %d best %d\n",u,best);
        if (n-numChild[u]-best<=n/2) res[u]=1; else res[u]=0;
    }
    FORE(it,adj[u]) if (*it!=par[u]) {
        int v=*it;
        myit.assign(sta[u],n-numChild[v]);
        myit.assign(sta[v],n);
        calcDFS(v);
        myit.assign(sta[u],n);
        myit.assign(sta[v],numChild[v]);
    }
}
void process(void) {
    rootDFS(1);
    FOR(i,1,n) if (isCentroid(i)) root=i;
    par[root]=0;
    prepareDFS(root);
    myit=SegmentTree(n);
    FOR(i,1,n) myit.assign(sta[i],numChild[i]);
    calcDFS(root);
    FOR(i,1,n) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    loadTree();
    process();
    return 0;
}