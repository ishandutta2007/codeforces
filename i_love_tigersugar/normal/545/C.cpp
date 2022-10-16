#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int x[MAX],h[MAX],n;
int f[MAX][2];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&x[i],&h[i]);
    FOR(i,1,n-1) assert(x[i]<x[i+1]);
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void optimize(void) {
    memset(f,-0x3f,sizeof f);
    f[1][0]=f[1][1]=1;
    FOR(i,2,n) REP(j,2) {
        int L=j?x[i-1]+h[i-1]:x[i-1];
        if (L<x[i]) maximize(f[i][0],f[i-1][j]);
        if (L<x[i]-h[i]) maximize(f[i][0],f[i-1][j]+1);
        if (L<x[i]) maximize(f[i][1],f[i-1][j]+1);
    }
    printf("%d\n",max(f[n][0],f[n][1]));
}
int main(void) {
    init();
    optimize();
    return 0;
}