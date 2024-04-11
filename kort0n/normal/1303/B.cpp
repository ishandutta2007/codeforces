#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    ll n, g, b;
    cin >> n >> g >> b;
    ll ok = 1e18;
    ll ng = n - 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll good = g * (mid / (g + b));
        ll rest = mid % (g + b);
        good += min(rest, g);
        ll bad = mid - good;
        if(good + min(n / 2, bad) >= n) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}