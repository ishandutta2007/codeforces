#include<cstdio>
#define MAX   211
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
bool f[MAX][MAX];
int a[MAX],n,s;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void init(void) {
    n=nextInt();
    FOR(i,1,n) a[i]=nextInt()/100;
    FOR(i,1,n) s+=a[i];
}
void optimize(void) {
    f[0][0]=true;
    REP(i,n) REP(j,s+1) if (f[i][j]) {
        f[i+1][j]=true;
        f[i+1][j+a[i+1]]=true;
    }
    if (s%2==0 && f[n][s/2]) printf("YES"); else printf("NO");
}
int main(void) {
    init();
    optimize();
    return 0;
}