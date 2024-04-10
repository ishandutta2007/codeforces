#include<bits/stdc++.h>
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
const int mod=(int)1e6+3;
int calcBitZero(long long L,long long R) {
    while (L%2!=0) L++;
    while (R%2!=0) R--;
    if (L>R) return (0);
    if (R<=100) {
        int res=0;
        FOR(i,L,R) {
            int tmp=i;
            while (tmp>0 && tmp%2==0) {
                res++;
                tmp/=2;
            }
        }
        return (res);
    }
    int tmp=(R/2-L/2+1)%(mod-1);
    return ((tmp+calcBitZero(L/2,R/2))%(mod-1));
}
int pw(long long n,long long k) {
    n%=mod;
    k%=mod-1;
    int res=1;
    int mul=n;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int inverse(int x) {
    return (pw(x,mod-2));
}
pair<int,int> solve(long long n,long long k) {
    if (n<=60 && MASK(n)<k) return (make_pair(1,1));
    int gcd=calcBitZero(MASK(min(n,62LL))-k+1,MASK(min(n,62LL))-1);
    if (k>mod+7) {
        int tmp=(n%(mod-1))*((k-1)%(mod-1))%(mod-1);
        tmp=(tmp-gcd+mod-1)%(mod-1);
        int res=pw(2,tmp);
        return (make_pair(res,res));
    }
    int tmp=(n%(mod-1))*((k-1)%(mod-1))%(mod-1);
    int p=pw(2,tmp);
    int q=pw(2,tmp);
    int mul=pw(2,n);
    int prod=1;
    FOR(i,1,k-1) prod=1LL*prod*(mul-i+mod)%mod;
    p=(p-prod+mod)%mod;
    int div=pw(2,gcd);
    return (make_pair(1LL*p*inverse(div)%mod,1LL*q*inverse(div)%mod));
}
int main(void) {
    long long n,k; cin>>n>>k;
    pair<int,int> res=solve(n,k);
    cout<<res.fi<<" "<<res.se<<endl;
    return 0;
}