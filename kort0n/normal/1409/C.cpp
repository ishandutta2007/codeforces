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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> ans;
    ll M = INF;
    for(ll d = 1; d <= 50; d++) {
        if((y - x) % d != 0) continue;
        ll a0 = y % d;
        if(a0 == 0) a0 += d;
        chmax(a0, y - (n - 1) * d);
        if(a0 > x) continue;
        if(chmin(M, a0 + (n - 1) * d)) {
            ans.clear();
            for(int i = 0; i < n; i++) {
                ans.push_back(a0 + d * i);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}