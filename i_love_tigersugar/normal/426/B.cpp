#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX][MAX];
int m,n;
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
}
bool equal(int x,int y) {
    FOR(i,1,n) if (a[x][i]!=a[y][i]) return (false);
    return (true);
}
bool symmetric(int k) {
    if (k&1) return (false);
    FOR(i,1,k/2) if (!equal(i,k+1-i)) return (false);
    return (true);
}
void process(void) {
    int res=m;
    while (symmetric(res)) res>>=1;
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}