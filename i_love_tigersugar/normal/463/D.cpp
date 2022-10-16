#include<cstdio>
#include<cstring>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
inline void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
int n,k,f[MAX],p[MAX][MAX];
void init(void) {
    n=nextint();
    k=nextint();
    REP(i,k) FOR(j,1,n) p[nextint()][i]=j;
    memset(f,-1,sizeof f);
}
bool after(int x,int y) {
    REP(i,k) if (p[x][i]>=p[y][i]) return (false);
    return (true);
}
int dp(int x) {
    if (f[x]>0) return (f[x]);
    int &res=f[x];
    res=1;
    FOR(i,1,n) if (after(i,x)) maximize(res,dp(i)+1);
    return (res);
}
void process(void) {
    int res=0;
    FOR(i,1,n) maximize(res,dp(i));
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}