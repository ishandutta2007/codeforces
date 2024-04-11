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
ll dp[201000];
ll num[201000];
void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i <= 2e5; i++) {
        dp[i] = num[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        num[a]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 2e5; i++) {
        dp[i] += num[i];
        chmax(ans, dp[i]);
        for(int j = 2 * i; j <= 2e5; j += i) {
            chmax(dp[j], dp[i]);
        }
    }
    cout << N - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}