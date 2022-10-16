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
ll dp[205][205][205];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S, T;
    cin >> S >> T;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        string A;
        A.push_back(S[i]);
        A.push_back(T[0]);
        A.push_back(T[1]);
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                for(auto c : A) {
                    ll newi = i + 1;
                    ll newj = j;
                    ll newk = k;
                    ll newval = dp[i][j][k];
                    if(c == T[1]) newval += j;
                    if(c == T[0]) newj++;
                    if(c != S[i]) newk++;
                    chmax(dp[newi][newj][newk], newval);
                }
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j <= N; j++) {
        for(int k = 0; k <= K; k++) {
            chmax(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}