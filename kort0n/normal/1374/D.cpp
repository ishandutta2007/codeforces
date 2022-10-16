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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ll delta = (K - a);
        delta %= K;
        delta += K;
        delta %= K;
        if(delta == 0) continue;
        ll val = mp[delta] * K + delta + 1;
        chmax(ans, val);
        mp[delta]++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}