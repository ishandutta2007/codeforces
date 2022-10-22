#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll k[mn];
ll lmul(ll a,ll b){
    if(a>inf/b)return inf;
    return a*b;
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll lpo(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=lmul(a,a))if(b&1)ans=lmul(ans,a);
    return ans;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll n,p;
        cin>>n>>p;
        for(int i=0;i<n;i++)cin>>k[i];
        sort(k,k+n);
        ll lk=k[n-1];
        ll ans=0,gp=0;
        for(int i=n-1;i>=0;i--){
            gp=lmul(gp,lpo(p,lk-k[i]));
            if(gp==0){
                gp++;
                ans+=po(p,k[i]);
            }
            else{
                gp--;
                ans-=po(p,k[i]);
            }
            ans%=mod;
            lk=k[i];
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
}