#include<bits/stdc++.h>
#define MAXN   100100
#define MAXK   505
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int INF=(int)1e9+7;
int up[MAXN],type[MAXN],c[MAXK];
int d[MAXK][MAXK];
int n,m,q;
int find(int x) {
    if (up[x]<0) return (x);
    up[x]=find(up[x]);
    return (up[x]);
}
void join(int u,int v) {
    int x=find(u);
    int y=find(v);
    if (x==y) return;
    up[y]=x;
}
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void loadgraph(void) {
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,q) {
        scanf("%d",&c[i]);
        c[i]+=c[i-1];
        FOR(j,c[i-1]+1,c[i]) type[j]=i;
    }
    memset(up,-1,sizeof up);
    memset(d,0x3f,sizeof d);
    FOR(i,1,q) d[i][i]=0;
    REP(i,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        if (c==0) join(u,v);
        minimize(d[type[u]][type[v]],c);
        minimize(d[type[v]][type[u]],c);
    }
}
void check(void) {
    FOR(i,1,q) {
        int set=find(c[i-1]+1);
        FOR(j,c[i-1]+1,c[i]) if (set!=find(j)) {
            printf("No");
            exit(0);
        }
    }
    printf("Yes\n");
}
void floyd(void) {
    FOR(i,1,q) FOR(j,1,q) FOR(k,1,q) minimize(d[j][k],d[j][i]+d[i][k]);
    FOR(i,1,q) FOR(j,1,q) {
        if (d[i][j]<INF) printf("%d",d[i][j]); else printf("-1");
        if (j<q) printf(" "); else printf("\n");
    }
}
int main(void) {
    loadgraph();
    check();
    floyd();
    return 0;
}