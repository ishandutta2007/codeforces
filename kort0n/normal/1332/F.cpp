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
const ll mod = 998244353;
ll N;
vector<ll> paths[301000];
ll dp[2][2][301000];
void dfs(int now, int from) {
    dp[0][0][now] = 1;
    dp[1][0][now] = 1;
    for(auto to : paths[now]) {
        if(to == from) continue;
        dfs(to, now);
        vector<ll> New[2];
        New[0].resize(2);
        New[1].resize(2);
        for(int v = 0; v <= 1; v++) {
            for(int e = 0; e <= 1; e++) {
                for(int c = 0; c <= 1; c++) {
                    for(int onc = 0; onc <= 1; onc++) {
                        for(int onp = 0; onp <= 1; onp++) {
                            if(v == 1 and e == 1 and c == 1) continue;
                            if(c == 1 and onc == 0 and e == 0) continue;
                            New[v][onp | e] += dp[v][onp][now] * dp[c][onc][to] % mod;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                dp[i][j][now] = New[i][j];
                dp[i][j][now] %= mod;
            }
        }
    }
    /*
    cerr << "---" << now << "---" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cerr << dp[i][j][now] << endl;
        }
    }
    */
}
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(0, -1);
    ll ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(i == 1 and j == 0) continue;
            ans += dp[i][j][0];
            ans %= mod;
        }
    }
    ans = (ans + mod - 1) % mod;
    cout << ans << endl;
    return 0;
}