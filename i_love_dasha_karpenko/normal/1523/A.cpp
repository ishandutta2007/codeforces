//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E3+7;
const ll INF = 1E18;
ll A[DIM],dp[DIM];
void solve(){
    ll n,m;
    cin>>n>>m;
    ll last = -INF;
    for(ll i = 1;i<=n;++i) {
        char ch;
        cin>>ch;
        A[i] = ch-'0';
        dp[i] = i-last;
        if (A[i])
            last = i;
    }
    last = INF;
    for(ll i = n;i>=1;--i){
        if (last-i!=dp[i] && min(dp[i],last-i)<=m)
            dp[i] = 1;
        else if (A[i])
            dp[i] =1;
        else dp[i] = 0;
        if (A[i])
            last = i;
    }
    for(ll i = 1;i<=n;++i)
        cout<<dp[i];
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    
    return 0;
}