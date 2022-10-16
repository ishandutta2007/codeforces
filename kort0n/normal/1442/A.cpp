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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll u = a[0];
    ll d = 0;
    for(int i = 1; i < N; i++) {
        ll tmpu = a[i];
        ll tmpd = 0;
        if(tmpu > u) {
            ll delta = tmpu - u;
            tmpu -= delta;
            tmpd += delta;
        }
        if(tmpd < d) {
            ll delta = d - tmpd;
            tmpd += delta;
            tmpu -= delta;
        }
        assert(tmpu <= u);
        assert(tmpd >= d);
        if(tmpu < 0 or tmpd < 0) {
            cout << "NO" << endl;
            return;
        }
        u = tmpu;
        d = tmpd;
    }
    cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}