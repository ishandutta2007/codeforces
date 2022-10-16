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
string S, T;

ll dp[5005][5005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) {
        for(int j = 0; j < T.size(); j++) {
            chmax(dp[i+1][j], dp[i][j] - 1);
            chmax(dp[i][j+1], dp[i][j] - 1);
            if(S[i] == T[j]) {
                chmax(dp[i+1][j+1], dp[i][j] + 2);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}