#include<bits/stdc++.h>
#define MAXN   300300
#define MAXK   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,k;
int a[MAXN];
long long f[MAXK][MAXK];
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
void init(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}
void optimize(void) {
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    int numBig=n%k;
    int numSmall=k-numBig;
    REP(i,numBig+1) REP(j,numSmall+1) {
        int tmp=i*(n/k+1)+j*(n/k);
        if (i<numBig) minimize(f[i+1][j],f[i][j]+a[tmp+n/k+1]-a[tmp+1]);
        if (j<numSmall) minimize(f[i][j+1],f[i][j]+a[tmp+n/k]-a[tmp+1]);
    }
    cout<<f[numBig][numSmall]<<endl;
}
int main(void) {
    init();
    optimize();
    return 0;
}