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
ll A, B, N;

ll f(ll i) {
    return B * (i - 1) + A;
}

void solve() {
    ll l, t, m;
    cin >> l >> t >> m;
    if(f(l) > t) {
        cout << -1 << endl;
        return;
    }
    ll ok = l;
    ll ng = 1e7;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        ll num = mid - l + 1;
        ll sum = num * (f(l) + f(mid)) / 2;
        ll T = (sum + m - 1) / m;
        chmax(T, f(mid));
        if(T <= t) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> N;
    while(N--) solve();
    return 0;
}