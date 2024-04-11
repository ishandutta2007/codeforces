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
    ll r, g, b;
    cin >> r >> g >> b;
    ll sum = r + b + g;
    string ans = "Yes";
    if(r > (sum + 1) / 2) ans = "No";
    if(g > (sum + 1) / 2) ans = "No";
    if(b > (sum + 1) / 2) ans = "No";
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}