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
    ll a, b;
    cin >> a >> b;
    ll rest = 0;
    for(int i = 0; i < 30; i++) {
        if(((a & (1 << i)) == (b & (1 << i)))) continue;
        if(a & (1 << i)) {
            ll tmp = __builtin_popcount(a);
            a += (1 << i);
            ll tmp2 = __builtin_popcount(a);
            rest += tmp - tmp2;
        } else {
            if(rest == 0) {
                cout << "NO" << endl;
                return;
            }
            rest--;
            a += (1 << i);
        }
    }
    if(a != b) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--) solve();
    return 0;
}