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
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = k * (k - 1) / 2;
    map<ll, ll> mpa, mpb;
    for(int i = 0; i < k; i++) {
        ll q;
        cin >> q;
        mpa[q]++;
    }
    for(int i = 0; i < k; i++) {
        ll q;
        cin >> q;
        mpb[q]++;
    }
    for(auto tmp : mpa) {
        ll val = tmp.second;
        ans -= val * (val - 1) / 2;
    }
    for(auto tmp : mpb) {
        ll val = tmp.second;
        ans -= val * (val - 1) / 2;
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