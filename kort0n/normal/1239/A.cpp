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
ll Fibonacci[100050];
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    Fibonacci[0] = 1;
    Fibonacci[1] = 1;
    for(ll i = 2; i <= 1e5; i++) {
        Fibonacci[i] = (Fibonacci[i-2] + Fibonacci[i-1]) % mod;
    }
    ll change = 2;
    ll rest = 2 * Fibonacci[N] - 2;
    rest %= mod;
    ll ans = 0;
    ans = change * Fibonacci[M];
    ans %= mod;
    ans += rest;
    ans %= mod;
    cout << ans << endl;
    return 0;
}