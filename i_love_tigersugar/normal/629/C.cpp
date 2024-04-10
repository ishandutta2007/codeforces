#include<bits/stdc++.h>
#define MAXN   100100
#define MAXL   2020
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod=(int)1e9+7;
char s[MAXN];
int m,n;
int left[MAXL][MAXL],right[MAXL][MAXL];
void init(void) {
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
}
void process(void) {
    left[0][0]=1;
    REP(i,n-m) REP(j,n-m+1) if (left[i][j]>0) {
        left[i+1][j+1]=(left[i+1][j+1]+left[i][j])%mod;
        if (j>0) left[i+1][j-1]=(left[i+1][j-1]+left[i][j])%mod;
    }
    int deg=0;
    int minDeg=0;
    FOR(i,1,m) {
        if (s[i]=='(') deg++; else deg--;
        minimize(minDeg,deg);
    }
    REP(i,n-m+1) REP(j,n-m+1) if (j+minDeg>=0 && j+deg<=n-m-i && left[i][j]>0)
        right[n-m-i][j+deg]=(right[n-m-i][j+deg]+left[i][j])%mod;
    FORD(i,n-m,1) REP(j,n-m+1) if (right[i][j]>0) {
        right[i-1][j+1]=(right[i-1][j+1]+right[i][j])%mod;
        if (j>0) right[i-1][j-1]=(right[i-1][j-1]+right[i][j])%mod;
    }
    printf("%d\n",right[0][0]);
}
int main(void) {
    init();
    process();
    return 0;
}