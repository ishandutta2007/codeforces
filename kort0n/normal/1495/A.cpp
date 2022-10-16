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
    vector<ll> v, u;
    for(int i = 0; i < 2 * N; i++) {
        ll a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        if(a == 0) v.push_back(b);
        else u.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    long double ans = 0;
    for(int i = 0; i < N; i++) {
        ans += hypot(v[i], u[i]);
    }
    cout << fixed << setprecision(30) << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}