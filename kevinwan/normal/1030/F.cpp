#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll bit[mn],bit2[mn],sa[mn];
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b;}
void upd2(int a,ll b){for(;a<mn;a+=a&-a)bit2[a]+=b,bit2[a]%=mod;}
ll qu(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
ll qu2(int a){ll b=0;for(;a;a-=a&-a)b+=bit2[a],b%=mod;return b;}
ll a[mn],w[mn];
int sch(ll x){
    int cur=0;
    ll sum=0;
    for(int i=1<<17;i;i>>=1){
        if(cur+i<mn&&sum+bit[cur+i]<=x)sum+=bit[cur+=i];
    }
    return cur+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]-=i;
    for(int i=1;i<=n;i++)cin>>w[i],upd(i,w[i]),upd2(i,w[i]*a[i]%mod);
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(l<0){
            l=-l;
            upd(l,r-w[l]);
            upd2(l,(r-w[l])*a[l]%mod);
            w[l]=r;
        }
        else{
            ll ls=qu(l-1),rs=qu(r);
            ll sum=rs-ls;
            int c=sch(sum/2+ls);
            ll cs=qu(c);
            ll ans=(qu2(r)-qu2(c)-(rs-cs)%mod*a[c]%mod)-(qu2(c)-qu2(l-1)-(cs-ls)%mod*a[c]%mod);
            ans%=mod;
            if(ans<0)ans+=mod;
            printf("%lld\n",ans);
        }
    }
}