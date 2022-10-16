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
    ll ans = 0;
    vector<ll> v;
    v.push_back(2050);
    while(v.back() <= N) {
        ll tmp = v.back() * 10;
        v.push_back(tmp);
    }
    reverse(v.begin(), v.end());
    for(auto tmp : v) {
        while(N >= tmp) {
            N -= tmp;
            ans++;
        }
    }
    if(N != 0) ans = -1;
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