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
const ll mod = 1000000007;

l_l dp[2050000];

void solve() {
    ll N;
    cin >> N;
    cout << 4 * dp[N].first % mod << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    dp[1] = {0, 0};
    dp[2] = {0, 0};
    for(int i = 3; i <= 2e6; i++) {
        ll fi = 0;
        ll se = 1;
        bool can = true;
        fi = 2 * dp[i-2].first + dp[i-1].first;
        fi %= mod;
        if(dp[i-2].second == 0 and dp[i-1].second == 0) {
            fi++;
            se = 1;
        } else {
            se = 0;
        }
        fi %= mod;
        dp[i] = {fi, se};
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}