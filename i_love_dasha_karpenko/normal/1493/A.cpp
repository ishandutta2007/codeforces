//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E9;
ll dp[DIM];
void solve(){
    memset(dp,0,sizeof(dp));
    ll n,k;
    cin>>n>>k;
    vector<ll> ans;
    for(ll i = k+1;i<=n;++i)
        ans.push_back(i);
    dp[0] = 1;
    for(ll i = k-1;i>=1;--i){
        if (dp[k-i])continue;
        for(ll j = k-i;j>=0;--j){
            dp[j+i] = max(dp[j+i],dp[j]);
        }
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}