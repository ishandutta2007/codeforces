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

const int INF = 1e9;
//const ll mod = 1000000007;
string S, T;
ll PAIR[10050];
int dp[10001][10001];

int main() {
    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) PAIR[i] = -1;
    stack<int> sta;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != '.') sta.push(i);
        else {
            if(!sta.empty()) {
                int idx = sta.top();
                sta.pop();
                PAIR[idx] = i;
            }
        }
    }
    for(int i = 0; i <= 1e4; i++) {
        for(int j = 0; j <= 1e4; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < S.size(); i++) {
        for(int j = 0; j <= T.size(); j++) {
            chmin(dp[i+1][j], dp[i][j] + 1);
            if(j < T.size() and T[j] == S[i]) {
                chmin(dp[i+1][j+1], dp[i][j]);
            }
            if(PAIR[i] != -1) {
                chmin(dp[PAIR[i]+1][j], dp[i][j]);
            }
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}