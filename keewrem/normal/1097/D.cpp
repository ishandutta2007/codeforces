#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007;
const int MAXN = 10000;
ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

int T = 1;
ll N,K;
void solve(){
    ll snv[100000];
    for(ll i = 0; i < 100000; i++)snv[i] = inv(i);
    cin >> N >> K;
    ll ans = 1;
    vector<pll> v;
    for(ll i = 2; i*i <= N; i++){
        if(N % i)continue;
        ll k = 0;
        while(N % i == 0){
            N /= i;
            k++;
        }
        v.pb({i,k});
    }
    if(N > 1)v.pb({N,1});
    ll p,c,t,cur;
    ll dp[K+1][60];
    for(auto [p,c]: v){

        for(int i = 0; i <= K; i++)for(int j = 0; j <= c; j++)dp[i][j] = 0;
        dp[0][c] = 1;
        for(int i = 0; i < K; i++){
            for(int j = 0; j <= c; j++){
                for(int k = 0; k <= j; k++){
                    dp[i+1][k] += dp[i][j] * snv[j+1];
                    dp[i+1][k] %= MOD;
                }
            }
        }
        t = 0, cur = 1;
        for(int i = 0; i <= c; i++){
            t += cur * dp[K][i];
            t %= MOD;
            cur = (cur * p)%MOD;
        }
    //    cout << ans << "\n";
        ans *= t;
        ans %= MOD;
    }
    cout << ans <<"\n";
}

int main(){
    while(T--){
        solve();
    }
    return 0;
}