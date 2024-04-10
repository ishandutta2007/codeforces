#include<bits/stdc++.h>
#define MAX   100100
#define SQR   333
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
const int mod=(int)1e9+7;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int frac[MAX],finv[MAX],pw25[MAX],pw26[MAX],invPw26[MAX];
int small[MAX][SQR+2],f[MAX],s[MAX];
int comb(int n,int k) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
void precalc(void) {
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) frac[i]=1LL*frac[i-1]*i%mod;
    FOR(i,1,MAX-1) finv[i]=pw(frac[i],mod-2);
    pw25[0]=pw26[0]=1;
    FOR(i,1,MAX-1) pw25[i]=25LL*pw25[i-1]%mod;
    FOR(i,1,MAX-1) pw26[i]=26LL*pw26[i-1]%mod;
    FOR(i,0,MAX-1) invPw26[i]=pw(pw26[i],mod-2);
}
void smallPrepare(void) {
    FOR(j,1,SQR) {
        small[j][j]=1;
        FOR(i,j+1,MAX-1) small[i][j]=(26LL*small[i-1][j]+1LL*pw25[i-j]*comb(i-1,j-1))%mod;
    }
}
void bigPrepare(int n) {
    FOR(i,n,MAX-1) f[i]=1LL*pw25[i-n]*comb(i-1,n-1)%mod*invPw26[i]%mod;
    s[n-1]=0;
    FOR(i,n,MAX-1) s[i]=(s[i-1]+f[i])%mod;
}
int answer(int n,int m) {
    if (m<=SQR) return (small[n][m]);
    if (n<m) return (0);
    return (1LL*s[n]*pw26[n]%mod);
}
void process(void) {
    int q;
    cin>>q;
    string s; cin>>s;
    if (s.size()>SQR) bigPrepare(s.size());
    REP(love,q) {
        int t; cin>>t;
        if (t==1) {
            cin>>s;
            if (s.size()>SQR) bigPrepare(s.size());
        } else {
            int n; cin>>n;
            printf("%d\n",answer(n,s.size()));
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    precalc();
    smallPrepare();
    process();
    return 0;
}