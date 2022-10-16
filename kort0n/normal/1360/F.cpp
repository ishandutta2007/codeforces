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

string dp[12][1 << 10];

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j < (1 << N); j++) {
            dp[i][j].clear();
        }
    }
    for(int i = 0; i < M; i++) {
        for(int before = 0; before < (1 << N); before++) {
            if(dp[i][before].size() != i) continue;
            for(int j = 0; j < N; j++) {
                string tmp = dp[i][before];
                tmp.push_back(S[j][i]);
                int to = 0;
                for(int k = 0; k < N; k++) {
                    if(S[j][i] != S[k][i]) {
                        to |= (1 << k);
                    }
                }
                if(to & before) continue;
                to |= before;
                dp[i+1][to] = tmp;
            }
        }
    }
    for(int i = 0; i < (1 << N); i++) {
        if(dp[M][i].empty()) continue;
        cout << dp[M][i] << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}