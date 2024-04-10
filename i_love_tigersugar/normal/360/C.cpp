#include<bits/stdc++.h>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int mod=(int)1e9+7;
int n,m;
char s[MAX];
int f[MAX][MAX],sumF[MAX][MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
}
void process(void) {
    f[0][0]=sumF[0][0]=1;
    FOR(i,1,n) REP(j,m+1) {
        f[i][j]=1LL*(s[i]-'a')*sumF[i-1][j]%mod;
        FOR(k,1,i) {
            if (j<k*(n-i+1)) break;
            f[i][j]=(f[i][j]+1LL*f[i-k][j-k*(n-i+1)]*('z'-s[i]))%mod;
        }
        sumF[i][j]=(sumF[i-1][j]+f[i][j])%mod;
    }
    int res=0;
    REP(i,n+1) res=(res+f[i][m])%mod;
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}