#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
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
int main(void) {
    int a,b;
    cin>>a>>b;
    int res=0;
    int inv=pw(2,mod-2);
    FOR(t,1,b-1)
        res=(res+1LL*a*b%mod*(a+1)%mod*inv%mod*t%mod+1LL*t*a%mod)%mod;
    cout<<res;
    return 0;
}