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
    ll L = 1e9;
    ll R = -1e9;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i]) {
            chmin(L, i);
            chmax(R, i);
        }
    }
    ll ans = 0;
    for(ll i = L; i <= R; i++) {
        if(a[i] == 0) ans++;
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