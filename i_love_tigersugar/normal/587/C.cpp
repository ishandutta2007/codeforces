#include<bits/stdc++.h>
#define MAX   100100
#define SIZE   12
#define LOG   17
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
vector<int> adj[MAX];
int par[MAX][LOG+1];
int idAt[MAX][LOG+1][2*SIZE+3],numAt[MAX][LOG+1];
int high[MAX];
int n,m,q;
int tmpArr[MAX],tmpSize;
void loadTree(void) {
    scanf("%d%d%d",&n,&m,&q);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i,1,m) {
        int t;
        scanf("%d",&t);
        if (numAt[t][0]<SIZE) idAt[t][0][numAt[t][0]++]=i;
    }
    high[0]=-1;
}
void dfs(int u) {
    FORE(it,adj[u]) if (*it!=par[u][0]) {
        int v=*it;
        par[v][0]=u;
        high[v]=high[u]+1;
        dfs(v);
    }
}
void joinArray(int a[],int b[],int c[],int na,int nb,int &nc) {
    nc=0;
    REP(i,na) c[nc++]=a[i];
    REP(i,nb) c[nc++]=b[i];
    if (nc>SIZE) {
        nth_element(c,c+SIZE-1,c+nc);
        nc=SIZE;
    }
    sort(c,c+nc);
}
void prepare(void) {
    dfs(1);
    FOR(j,1,LOG) FOR(i,1,n) {
        par[i][j]=par[par[i][j-1]][j-1];
        joinArray(idAt[i][j-1],idAt[par[i][j-1]][j-1],idAt[i][j],
                    numAt[i][j-1],numAt[par[i][j-1]][j-1],numAt[i][j]);
    }
}
int LCA(int u,int v) {
    if (high[v]>high[u]) return (LCA(v,u));
    FORD(i,LOG,0) if (high[par[u][i]]>=high[v]) u=par[u][i];
    if (u==v) return (u);
    FORD(i,LOG,0) if (par[u][i]!=par[v][i]) {
        u=par[u][i];
        v=par[v][i];
    }
    return (par[u][0]);
}
void addArray(int a[],int n) {
    REP(i,n) tmpArr[tmpSize++]=a[i];
}
void jump(int u,int h) {
    FORD(i,LOG,0) if (MASK(i)<=h) {
        addArray(idAt[u][i],numAt[u][i]);
        u=par[u][i];
        h-=MASK(i);
    }
}
void query(int u,int v,int req) {
    tmpSize=0;
    int w=LCA(u,v);
    jump(u,high[u]-high[w]);
    jump(v,high[v]-high[w]);
    addArray(idAt[w][0],numAt[w][0]);
    if (tmpSize>req) {
        nth_element(tmpArr,tmpArr+req-1,tmpArr+tmpSize);
        tmpSize=req;
    }
    sort(tmpArr,tmpArr+tmpSize);
    printf("%d",tmpSize);
    REP(i,tmpSize) printf(" %d",tmpArr[i]); printf("\n");
}
void process(void) {
    REP(love,q) {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        query(u,v,t);
    }
}
int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}