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
    ll l, r, m;
    cin >> l >> r >> m;
    for(ll a = l; a <= r; a++) {
        ll n = m / a;
        ll b = l;
        ll c = l;
        b = m - n * a + c;
        if(n > 0 and l <= b and b <= r) {
            cout << a << " " << b << " " << c << endl;
            return;
        }
        n++;
        b = l;
        c = l;
        c = n * a + b - m;
        if(n > 0 and l <= b and c <= r) {
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }
    assert(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}