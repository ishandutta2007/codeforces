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

ll f(ll a) {
    string S = to_string(a);
    ll maxi = 0;
    ll mini = 9;
    for(auto c : S) {
        ll d= (ll)(c - '0');
        chmax(maxi, d);
        chmin(mini, d);
    }
    return maxi * mini;
}

void solve() {
    ll a, k;
    cin >> a >> k;
    k--;
    while(k--) {
        ll delta = f(a);
        if(delta == 0) break;
        a += delta;
    }
    cout << a << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}