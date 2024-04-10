#include<bits/stdc++.h>
#define MAX   5050
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
int same[MAX][MAX],f[MAX][MAX],sum[MAX][MAX];
int n,m;
char s[MAX];
void init(void) {
    scanf("%d",&n);
    scanf("%s",s+1);
}
void prepare(void) {
    FOR(i,1,n) same[i][n]=same[n][i]=s[i]==s[n];
    FORD(i,n-1,1) FORD(j,n-1,1) same[i][j]=s[i]==s[j]?same[i+1][j+1]+1:0;
}
bool ok(int i,int j) {
    int t=2*j-i-1;
    if (same[t][j]>=i-j+1) return (false);
    return (s[t+same[t][j]]<s[j+same[t][j]]);
}
void optimize(void) {
    f[1][1]=sum[1][1]=1;
    FOR(i,1,n) FOR(j,1,i) {
        if (s[j]=='0') {
            f[i][j]=0;
            sum[i][j]=sum[i][j-1];
            continue;
        }
        if (j==1) {
            f[i][j]=sum[i][j]=1;
            continue;
        }
        if (j<i) {
            f[i][j]=(f[i][j]+sum[j-1][j-1])%mod;
            if (2*j-i-1>=1) f[i][j]=(f[i][j]-sum[j-1][2*j-i-1]+mod)%mod;
        }
        if (2*j-i-1>=1 && ok(i,j)) f[i][j]=(f[i][j]+f[j-1][2*j-i-1])%mod;
        sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
    }
    printf("%d\n",sum[n][n]);
}
int main(void) {
    init();
    prepare();
    optimize();
    return 0;
}