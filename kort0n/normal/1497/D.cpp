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
ll dp[5005];
ll tag[5005];
ll s[5005];

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i <= N; i++) dp[i] = 0;
    for(int i = 0; i < N; i++) cin >> tag[i];
    for(int i = 0; i < N; i++) cin >> s[i];
    for(int i = 0; i < N; i++) {
        ll maxi = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(tag[j] == tag[i]) continue;
            ll tmp = dp[j] + abs(s[j] - s[i]);
            chmax(dp[j], maxi + abs(s[j] - s[i]));
            chmax(maxi, tmp);
        }
        chmax(dp[i], maxi);
        /*
        for(int k = 0; k < N; k++) {
            cerr << dp[k] << " ";
        }
        cerr << endl;
        */
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) chmax(ans, dp[i]);
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