#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll qpow(ll a,ll b){
    ll ans=1;
    while (b){
        if (b&1) ans=ans*a%mod;
        a=a*a%mod; b>>=1;
    }
    return ans;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",qpow(qpow(2,b)-1,a));
    return 0;
}