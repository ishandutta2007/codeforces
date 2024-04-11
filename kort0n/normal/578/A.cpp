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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
double f(double delta, double border) {
    ll ok = 1;
    ll ng = 1e9 + 1;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        double val = delta / 2 / mid;
        if(val >= border) ok = mid;
        else ng = mid;
    }
    return delta / 2 / ok;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    if(a < b) {
        cout << -1 << endl;
        return 0;
    }
    if(a == b) {
        cout << a << endl;
        return 0;
    }
    double ans = 1e10;
    double asub = a - b;
    double now = f(asub, b);
    if(now + EPS >= b) chmin(ans, now);
    asub = a + b;
    now = f(asub, b);
    if(now + EPS >= b) chmin(ans, now);
    cout << fixed << setprecision(15) << ans << endl;
    /*
    long double x = (a + b) / (long double)2.0;
    while(x / 2.0 >= b - 1e-12) x /= 2.0;
    long double y = (long double)(a - b) / 2;
    while(y / 2.0 >= b - 1e-12) y /= 2.0;
    if(x >= b - 1e-12) chmin(x, y);
    cout << fixed << setprecision(15) << x << endl;
    */
    return 0;
}