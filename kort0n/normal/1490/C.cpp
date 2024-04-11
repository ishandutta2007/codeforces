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
vector<ll> v;
void solve() {
    ll x;
    cin >> x;
    string ans = "NO";
    for(auto val : v) {
        auto itr = lower_bound(v.begin(), v.end(), x - val);
        if(itr != v.end() and *itr + val == x) ans = "YES";
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(ll i = 1; i * i * i <= 1e12; i++) {
        v.push_back(i * i * i);
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}