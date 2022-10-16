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
vector<l_l> f(ll x) {
    vector<l_l> ret;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i != 0) continue;
        ret.push_back({i, 0});
        while(x % i == 0) {
            x /= i;
            ret.back().second++;
        }
    }
    if(x != 1) {
        ret.push_back({x, 1});
    }
    return ret;
}
void solve() {
    ll N;
    cin >> N;
    auto v = f(N);
    ll k = 0;
    for(auto tmp : v) {
        chmax(k, tmp.second);
    }
    vector<ll> w(k, 1);
    for(auto tmp : v) {
        //cerr << tmp.first << ", " << tmp.second << endl;
        for(int i = 0; i < tmp.second; i++) {
            w[w.size()-1-i] *= tmp.first;
        }
    }
    cout << k << endl;
    for(auto tmp : w) {
        cout << tmp << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}