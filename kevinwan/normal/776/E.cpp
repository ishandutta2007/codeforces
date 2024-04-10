#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll num[mn];
ll f(ll x){
    ll ans=1;
    for(ll i=2;i*i<=x;i++){
        bool g=0;
        while(x%i==0){
            g=1;
            x/=i;
            ans*=i;
        }
        if(g){
            ans/=i;
            ans*=i-1;
        }
    }
    if(x!=1)ans*=x-1;
    return ans;
}
int main()
{
    ll n,k,i;
    cin>>n>>k;
    k=(k+1)/2;

    while(k--&&n!=1){
        n=f(n);
    }
    printf("%lld",n%1000000007);
}