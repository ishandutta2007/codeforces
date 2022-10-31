//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll MOD = 998244353;
const ll DIM = 1E6+7;
ll divs[DIM],dp[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = i*2;j<=n;j+=i)
            ++divs[j];
        dp[i] =(divs[i]+1+sum)%MOD;
        sum=(sum+dp[i])%MOD;
    }
    cout<<dp[n]<<endl;
    return 0;
}