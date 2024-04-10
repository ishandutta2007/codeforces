#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
bool ask(ll l,ll r){
    printf("%lld %lld\n",l,r);
    fflush(stdout);
    string s;
    cin>>s;
    return s[0]=='Y';
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll l=1,r=n;
    while(1){
        while(r-l>4*k+2){
            ll mid=r+l>>1;
            if(ask(l,mid))l=l-k,r=mid+k;
            else r=r+k,l=mid-k;
            l=max(l,1LL);
            r=min(r,n);
        }
        ll ans=l+rng()%(r-l+1);
        if(ask(ans,ans))return 0;
        l-=2*k;
        r+=2*k;
        l=max(l,1LL);
        r=min(r,n);
    }
}