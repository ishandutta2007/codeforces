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
    ll x, y, z;
    cin >> x >> y >> z;
    if(x == y and y == z) {
        cout << "YES" << endl;
        cout << x << " " << x << " " << x << endl;
    } else if(x == y and x > z) {
        cout << "YES" << endl;
        cout << x << " " << z << " " << z << endl;
    } else if(x == z and x > y) {
        cout << "YES" << endl;
        cout << y << " " << x << " " << y << endl;
    } else if(z == y and y > x) {
        cout << "YES" << endl;
        cout << x << " " << x << " " << y << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}