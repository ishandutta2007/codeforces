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
ll dp[2005][2005];
ll Ssum[26][2005];
ll Tsum[26][2005];

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j <= N; j++) {
            Ssum[i][j] = 0;
            Tsum[i][j] = 0;
        }
    }
    string S, T;
    cin >> S >> T;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < N; j++) {
            Ssum[i][j+1] = Ssum[i][j];
            if(S[j] == (char)('a' + i)) Ssum[i][j+1]++;
            Tsum[i][j+1] = Tsum[i][j];
            if(T[j] == (char)('a' + i)) Tsum[i][j+1]++;
        }
    }
    map<char, int> mpS, mpT;
    for(auto c : S) mpS[c]++;
    for(auto c : T) mpT[c]++;
    for(char a = 'a'; a <= 'z'; a++) {
        if(mpS[a] != mpT[a]) {
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i < N and j < N and S[i] == T[j]) {
                chmin(dp[i+1][j+1], dp[i][j]);
            }
            chmin(dp[i][j+1], dp[i][j] + 1);
            int idx = (int)(S[i] - 'a');
            if(i < N and Ssum[idx][i] < Tsum[idx][j]) {
                chmin(dp[i+1][j], dp[i][j]);
            }
            //chmin(dp[i][j+1], dp[i][j]);
        }
    }
    cout << dp[N][N] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}