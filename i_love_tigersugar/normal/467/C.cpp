#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0;_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
ll a[MAX],s[MAX];
ll f[MAX][MAX];
int m,n,k;
inline void maximize(ll &x,const ll &y) {
    if (x<y) x=y;
}
void init(void) {
    cin>>n>>m>>k;
    FOR(i,1,n) {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
}
void optimize(void) {
    memset(f,-1,sizeof f);
    f[0][0]=0;
    FOR(i,1,n) FOR(j,0,k) {
        if (f[i-1][j]>=0) f[i][j]=f[i-1][j];
        if (i>=m && j>=1 && f[i-m][j-1]>=0) maximize(f[i][j],f[i-m][j-1]+s[i]-s[i-m]);
    }
    cout<<f[n][k];
}
int main(void) {
    ios::sync_with_stdio(false);
    init();
    optimize();
    return 0;
}