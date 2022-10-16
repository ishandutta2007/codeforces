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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    ll a, m;
    cin >> a >> m;
    vector<ll> primes;
    ll copy = m;
    for(ll i = 2; i * i <= copy; i++) {
        if(copy % i == 0) {
            primes.push_back(i);
            while(copy % i == 0) copy /= i;
        }
    }
    if(copy != 1) primes.push_back(copy);
    vector<ll> divisors;
    for(ll i = 1; i * i <= m; i++) {
        if(m % i != 0) continue;
        divisors.push_back(i);
        if(i * i != m) divisors.push_back(m / i);
    }
    /*
    sort(divisors.begin(), divisors.end(), greater<ll>());
    map<ll, ll> dp;
    for(auto now : divisors) {
        dp[now] += m / now;
        for(int bits = 1; bits < (1 << primes.size()); bits++) {
            bool ok = true;
            ll val = now;
            for(int i = 0; i < primes.size(); i++) {
                if(bits & (1 << i)) {
                    if(val % primes[i] != 0) ok = false;
                    val /= primes[i];
                }
            }
            if(!ok) continue;
            if(m % val != 0) continue;
            if(__builtin_popcount(bits) % 2 == 0) {
                dp[val] += dp[now];
            } else {
                dp[val] -= dp[now];
            }
        }
        cerr << now << " " << dp[now] << endl;
        if(now == __gcd(a, m)) {
            //cout << dp[now] << endl;
        }
    }
    */
    ll ans = 0;
    for(int bits = 0; bits < (1 << primes.size()); bits++) {
        ll val = __gcd(a, m);
        for(int i = 0; i < primes.size(); i++) {
            if(bits & (1 << i)) val *= primes[i];
        }
        if(m % val != 0) continue;
        if(__builtin_parity(bits)) ans -= m / val;
        else ans += m / val;
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}