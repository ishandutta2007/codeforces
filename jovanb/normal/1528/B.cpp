#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    return (1LL*a*b)%MOD;
}

ll dp[1000005];
ll sum[1000005];
ll divs[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=1; i<=1000000; i++){
        for(int j=2*i; j<=1000000; j+=i){
            divs[j]++;
        }
    }
    ll N;
    cin >> N;
    ll res = 0;
    dp[0] = 1;
    sum[0] = 1;
    for(ll n=1; n<=N; n++){
        dp[n] = add(dp[n], sum[n-1]);
        dp[n] = add(dp[n], divs[n]);
        sum[n] = add(sum[n-1], dp[n]);
    }
    cout << dp[N];
    return 0;
}