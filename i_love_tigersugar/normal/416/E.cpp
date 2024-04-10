#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int INF=(int)1e9+7;
int c[MAX][MAX];
int d[MAX][MAX];
int cnt[MAX][MAX];
int n,m;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void loadgraph(void) {
    memset(c,0x3f,sizeof c);
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        minimize(c[u][v],w);
        minimize(c[v][u],w);
    }
}
void floyd(void) {
    memset(d,0x3f,sizeof d);
    FOR(i,1,n) FOR(j,1,n) minimize(d[i][j],c[i][j]);
    FOR(i,1,n) d[i][i]=0;
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) minimize(d[j][k],d[j][i]+d[i][k]);
    FOR(i,1,n) FOR(j,1,n) if (d[i][j]<INF)
        FOR(k,1,n) if (d[i][k]<INF && c[k][j]<INF && d[i][k]+c[k][j]==d[i][j]) cnt[i][j]++;
}
void process(void) {
    bool fst=true;
    FOR(i,1,n) FOR(j,i+1,n) {
        int res=0;
        FOR(k,1,n) if (d[i][k]+d[k][j]==d[i][j]) res+=cnt[i][k];
        if (!fst) printf(" "); else fst=false;
        printf("%d",res);
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    loadgraph();
    floyd();
    process();
    return 0;
}