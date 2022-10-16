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
    ll d, mod;
    cin >> d >> mod;
    vector<ll> v;
    v.push_back(1);
    for(int i = 1; ; i++) {
        if(d >= (1 << (i+1))) {
            v.push_back(1 << i);
        } else {
            v.push_back(d - (1 << (i)) + 1);
            break;
        }
    }
    ll ans = 1;
    for(auto tmp : v) {
        //cerr << tmp << " ";
        ans *= tmp + 1;
        ans %= mod;
    }
    //cerr << endl;
    ans += mod - 1;
    ans %= mod;
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