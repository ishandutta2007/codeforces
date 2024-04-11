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
ll ans;
vector<ll> r, g, b;
void f() {
    for(int i = 0; i < r.size(); i++) {
        auto itr = lower_bound(g.begin(), g.end(), r[i]);
        if(itr == g.end()) continue;
        auto itr2 = lower_bound(b.begin(), b.end(), (*itr + r[i]) / 2);
        if(itr2 != b.end()) {
        ll tmp = 0;
        ll tmp2;
        tmp2 = r[i] - *itr;
        tmp += tmp2 * tmp2;
        tmp2 = r[i] - *itr2;
        tmp += tmp2 * tmp2;
        tmp2 = *itr - *itr2;
        tmp += tmp2 * tmp2;
        if(chmin(ans, tmp)) {
        }
        }
        if(itr2 != b.begin()) {
            itr2--;
        ll tmp = 0;
        ll tmp2;
        tmp2 = r[i] - *itr;
        tmp += tmp2 * tmp2;
        tmp2 = r[i] - *itr2;
        tmp += tmp2 * tmp2;
        tmp2 = *itr - *itr2;
        tmp += tmp2 * tmp2;
        if(chmin(ans, tmp)) {
        }
        }
    }
}
void solve() {
    ans = LONG_LONG_MAX;
    ll nr, ng, nb;
    cin >> nr >> ng >> nb;
    r.resize(nr);
    g.resize(ng);
    b.resize(nb);
    for(int i = 0; i < nr; i++) cin >> r[i];
    for(int i = 0; i < ng; i++) cin >> g[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    f();
    swap(b, g);
    f();
    swap(r, g);
    f();
    swap(g, b);
    f();
    swap(r, g);
    f();
    swap(g, b);
    f();
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}