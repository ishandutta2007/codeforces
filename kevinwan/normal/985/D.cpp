#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x7fffffffffffffff;
inline ll m(ll a,ll b){return (b&&a>inf/b)?inf:(a*b);}
ll n,h;
ll idk(ll x){
    ll num=min(x,(x+h)/2);
    ll tot=m(num,num+1)/2;
    x-=num;
    tot+=m(h+(h+x-1),x)/2;
    return tot;
}
int main()
{
    cin>>n>>h;
    ll cur=0;
    for(ll i=1LL<<30;i;i>>=1){
        if(idk(cur+i)<n)cur+=i;
    }
    printf("%lld",cur+1);
}