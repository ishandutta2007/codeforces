#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;

void solve() {
    ll N;
    cin >> N;
    ll anslcm = 1e18;
    ll ans1, ans2;
    for(ll i = 1; i * i <= N; i++) {
        if(N % i != 0) continue;
        ll tmp1 = i;
        ll tmp2 = N / i;
        if(tmp1 != N) {
            ll a = tmp1;
            ll b = N - a;
            ll L = a * b / __gcd(a, b);
            if(chmin(anslcm, L)) {
                ans1 = a;
                ans2 = b;
            }
        }
        if(tmp2 != N) {
            ll b = tmp2;
            ll a = N - b;
            ll L = a * b / __gcd(a, b);
            if(chmin(anslcm, L)) {
                ans1 = a;
                ans2 = b;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}