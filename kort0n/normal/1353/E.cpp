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

ll dp[1050000][3];
ll ans = 1e9;

ll f(string S) {
    ll N = S.size();
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        chmin(dp[i+1][0], dp[i][0] + (S[i] == '1'));
        chmin(dp[i+1][1], dp[i][0] + (S[i] == '0'));
        chmin(dp[i+1][1], dp[i][1] + (S[i] == '0'));
        chmin(dp[i+1][2], dp[i][1] + (S[i] == '1'));
        chmin(dp[i+1][2], dp[i][2] + (S[i] == '1'));
    }
    ll ret = INF;
    for(int i = 0; i < 3; i++) {
        chmin(ret, dp[N][i]);
    }
    return ret;
}

void solve() {
    ans = 1e9;
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll total = 0;
    for(auto c : S) {
        total += (c == '1');
    }
    for(int i = 0; i < K; i++) {
        string T;
        ll tmp = 0;
        for(int j = i; j < N; j += K) {
            T.push_back(S[j]);
            tmp += (S[j] == '1');
        }
        chmin(ans, f(T) + total - tmp);
    }
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