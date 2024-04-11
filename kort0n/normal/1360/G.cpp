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
    ll n, m, a, b;
    cin >> n >> m >> a>> b;
    if(n*a != m * b) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<string> ans(n, string(m, ('0')));
    ll h = 0;
    ll w = 0;
    for(ll num = 0; num < n * a; num++) {
        ans[h][w] = '1';
        h = (h + 1) % n;
        w = (w + 1) % m;
        while(num < n*a - 1 and ans[h][w] == '1') {
            w = (w + 1) % m;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}