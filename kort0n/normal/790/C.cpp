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
int N;
vector<int> V, K, Others;
string S;
ll dp[80][80][80][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> S;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'V')  V.push_back(i);
        else if(S[i] == 'K') K.push_back(i);
        else Others.push_back(i);
    }
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                for(int l = 0; l <= 1; l++) {
                    dp[i][j][k][l] = 1e18;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int i = 0; i <= V.size(); i++) {
        for(int j = 0; j <= K.size(); j++) {
            for(int k = 0; k <= Others.size(); k++) {
                for(int l = 0; l <= 1; l++) {
                    if(i < V.size()) {
                        ll cost = dp[i][j][k][l];
                        for(int m = 0; m < i; m++) {
                            if(V[m] > V[i]) cost++;
                        }
                        for(int m = 0; m < j; m++) {
                            if(K[m] > V[i]) cost++;
                        }
                        for(int m = 0; m < k; m++) {
                            if(Others[m] > V[i]) cost++;
                        }
                        chmin(dp[i+1][j][k][1], cost);
                    }
                    if(j < K.size() and l == 0) {
                        ll cost = dp[i][j][k][l];
                        for(int m = 0; m < i; m++) {
                            if(V[m] > K[j]) cost++;
                        }
                        for(int m = 0; m < j; m++) {
                            if(K[m] > K[j]) cost++;
                        }
                        for(int m = 0; m < k; m++) {
                            if(Others[m] > K[j]) cost++;
                        }
                        chmin(dp[i][j+1][k][0], cost);
                    }
                    if(k < Others.size()) {
                        ll cost = dp[i][j][k][l];
                        for(int m = 0; m < i; m++) {
                            if(V[m] > Others[k]) cost++;
                        }
                        for(int m = 0; m < j; m++) {
                            if(K[m] > Others[k]) cost++;
                        }
                        for(int m = 0; m < k; m++) {
                            if(Others[m] > Others[k]) cost++;
                        }
                        chmin(dp[i][j][k+1][0], cost);
                    }
                }
            }
        }
    }
    ll ans = dp[V.size()][K.size()][Others.size()][0];
    chmin(ans, dp[V.size()][K.size()][Others.size()][1]);
    cout << ans << endl;
    return 0;
}