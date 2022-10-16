#include <bits/stdc++.h>
//#include <atcoder/all>
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
bool f(vector<ll> a) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != a[0]) return false;
    }
    return true;
}
bool g(vector<ll> a) {
    for(int i = 0; i + 1 < a.size(); i++) {
        if(abs(a[i+1] - a[i]) >= 2) return false;
    }
    return true;
}

void solve() {
    ll n, u, v;
    cin >> n >> u >> v;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    if(f(a)) {
        ans = v + min(u, v);
    } else if(g(a)) {
        ans = min(u, v);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}