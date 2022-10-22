//#pragma comment(linker, "/STACK:2000000000")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll a[mn];
lll imp[mn],dp[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,ra,rb,rc,d;
    cin>>n>>ra>>rb>>rc>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    lll def=d*(n-1);
    for(int i=1;i<=n;i++)def+=ra*a[i]+rc;
    for(int i=1;i<=n;i++)imp[i]=ra*a[i]+rc-min(rb+ra,ra*(a[i]+2));
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(i>=2)dp[i]=max(dp[i],dp[i-2]+imp[i-1]+imp[i]-2*d);
        if(i+1==n)dp[i]=max(dp[i],dp[i-1]+imp[i]-d);
        if(i==n)dp[i]=max(dp[i],dp[i-1]+imp[i]-2*d);
    }
    ll ans=def-dp[n];
    printf("%lld",ans);
}