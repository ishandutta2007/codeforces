#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b /2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}
ll N, K;
ll ans = 1;
ll dp[60][10500];
void f(ll val, ll initial) {
    for(int i = 0; i < 60; i++) {
        for(int j = 0; j <= 1e4; j++) dp[i][j] = 0;
    }
    dp[initial][0] = 1;
    for(int timer = 0; timer < K; timer++) {
        for(int before = 0; before <= initial; before++) {
            ll factor = beki(before + 1, mod - 2);
            for(ll after = 0; after <= before; after++) {
                dp[after][timer+1] += dp[before][timer] * factor;
                dp[after][timer+1] %= mod;
            }
        }
    }
    ll now = 0;
    for(int i = 0; i <= initial; i++) {
        now += beki(val, i) * dp[i][K];
        now %= mod;
    }
    ans *= now;
    ans %= mod;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(ll i = 2; i * i <= N; i++) {
        ll num = 0;
        while(N % i == 0) {
            num++;
            N /= i;
        }
        if(num > 0) f(i, num);
    }
    if(N > 1) f(N, 1);
    cout << ans << endl;
    return 0;
}