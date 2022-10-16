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
    ll N;
    cin >> N;
    vector<ll> a(N + 2);
    for(int i = 1; i <= N; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i < a.size(); i++) {
        ans += abs(a[i] - a[i-1]);
    }
    for(int i = 1; i <= N; i++) {
        if(a[i] > a[i-1] and a[i] > a[i+1]) {
            ans -= a[i] - max(a[i-1], a[i+1]);
        }
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