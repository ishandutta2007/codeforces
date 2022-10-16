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

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll g = 0;
    for(int i = 1; i < N; i++) {
        g = __gcd(g, abs(a[i] - a[0]));
    }
    ll delta = abs(K - a[0]);
    string ans = "NO";
    if(delta == 0) {
        ans = "YES";
    } else if(g != 0 and delta % g == 0) {
        ans = "YES";
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