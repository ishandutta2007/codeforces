#include<cstdio>
#include<cstdlib>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
const int mod=(int)1e9+7;
int a[MAX],n,h;
int f[MAX][MAX];
inline void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void init(void) {
    scanf("%d%d",&n,&h);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) if (a[i]>h) {
        printf("0");
        exit(0);
    }
}
void optimize(void) {
    f[0][0]=1;
    REP(i,n) REP(j,i+1) if (f[i][j]>0)
        REP(e,2) REP(s,2) if (e<=j && a[i+1]+j-e+s==h)
            add(f[i+1][j-e+s],e?1LL*f[i][j]*j%mod:f[i][j]);
    printf("%d",(f[n][0]+f[n][1])%mod);
}
int main(void) {
    init();
    optimize();
    return 0;
}