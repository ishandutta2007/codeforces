#include<bits/stdc++.h>
#define MAXN   30030
#define MAXD   404
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
const int n=30000;
int f[MAXN][2*MAXD];
int cnt[MAXN];
int m,d;
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d%d",&m,&d);
    REP(zz,m) {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
}
bool validMove(int x,int y) {
    if (y<1) return (false);
    if (x+y>n) return (false);
    return (true);
}
void optimize(void) {
    memset(f,-1,sizeof f);
    f[d][MAXD]=cnt[d];
    int res=cnt[d];
    FOR(i,d,n) FOR(j,-400,400) if (f[i][j+MAXD]>=0) {
        maximize(res,f[i][j+MAXD]);
        FOR(k,-1,1) if (validMove(i,d+j+k)) maximize(f[i+d+j+k][j+k+MAXD],f[i][j+MAXD]+cnt[i+d+j+k]);
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}