#include<bits/stdc++.h>
#define MAX   2222
#define LOG   13
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int d[MAX][MAX];
vector<int> ch[MAX];
int par[MAX][LOG+1];
int toRoot[MAX],lv[MAX];
int n;
void exit_no(void) {
    printf("NO");
    exit(0);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&d[i][j]);
}
void precheck(void) {
    FOR(i,1,n) FOR(j,1,n) {
        if (i==j && d[i][j]!=0) exit_no();
        if (i!=j && d[i][j]<=0) exit_no();
        if (d[i][j]!=d[j][i]) exit_no();
    }
}
bool cmp(const int &x,const int &y) {
    return (d[1][x]<d[1][y]);
}
void prepare(void) {
    lv[0]=-1;
    FOR(i,1,n) FOR(j,1,n) if (i!=j && d[1][i]+d[i][j]==d[1][j])
        ch[i].push_back(j);
    FOR(i,1,n) sort(ch[i].begin(),ch[i].end(),cmp);
}
void dfs(int u) {
    FORE(it,ch[u]) if (par[*it][0]<=0) {
        par[*it][0]=u;
        toRoot[*it]=toRoot[u]+d[*it][u];
        lv[*it]=lv[u]+1;
        dfs(*it);
    }
}
void setupLCA(void) {
    dfs(1);
    FOR(i,2,n) if (par[i][0]<=0) exit_no();
    FOR(j,1,LOG) FOR(i,1,n) par[i][j]=par[par[i][j-1]][j-1];
}
int LCA(int u,int v) {
    if (lv[u]<lv[v]) return (LCA(v,u));
    FORD(i,LOG,0) if (lv[par[u][i]]>=lv[v]) u=par[u][i];
    if (u==v) return (u);
    FORD(i,LOG,0) if (par[u][i]!=par[v][i]) {
        u=par[u][i];
        v=par[v][i];
    }
    return (par[u][0]);
}
int dis(int u,int v) {
    return (toRoot[u]+toRoot[v]-2*toRoot[LCA(u,v)]);
}
void finalcheck(void) {
    FOR(i,1,n) FOR(j,1,n) if (dis(i,j)!=d[i][j]) exit_no();
    printf("YES");
}
int main(void) {
    init();
    precheck();
    prepare();
    setupLCA();
    finalcheck();
    return 0;
}