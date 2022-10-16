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
int TEN(int x) {
    int ret = 1;
    for(int i = 0; i < x; i++) ret *= 10;
    return ret;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = TEN(a - c);
    int y = TEN(b - c);
    if(a >= b) x++;
    if(a < b) y++;
    for(int i = 2; i <= c; i++) {
        x *= 10;
        y *= 10;
    }
    int g = __gcd(x, y);
    //assert(TEN(c - 1) <= g and g < TEN(c));
    cout << x << " " << y << endl;
    cerr << g << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}