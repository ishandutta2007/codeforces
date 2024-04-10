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
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const int mod=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int pw(int n,int k,int mod) {
    int res=1;
    int mul=n;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int main(void) {
    int p,k;
    cin>>p>>k;
    if (k==0) {
        cout<<pw(p,p-1,mod)<<endl;
        return 0;
    }
    int cnt0=k==1?p:1;
    int cyc=0;
    FOR(i,1,p+7) if (pw(k,i,p)==1) {
        cyc=i;
        break;
    }
    cout<<1LL*cnt0*pw(p,(p-1)/cyc,mod)%mod<<endl;
    return 0;
}