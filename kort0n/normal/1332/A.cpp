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

bool solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x1, x2, y1, y2;
    ll x, y;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
        if(a != 0 or b != 0) return false;
    }
    if(y1 == y2) {
        if(c != 0 or d != 0) return false;
    }
    x += b - a;
    if(x < x1 or x > x2) return false;
    y += d - c;
    if(y < y1 or y > y2) return false;
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        if(solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}