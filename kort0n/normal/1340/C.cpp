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
ll dp[10000][1001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<ll> d(M);
    for(int i = 0; i < M; i++) cin >> d[i];
    sort(d.begin(), d.end());
    ll g, r;
    cin >> g >> r;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j <= g; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    deque<i_i> deq;
    deq.push_front({0, 0});
    while(!deq.empty()) {
        auto now = deq.front();
        deq.pop_front();
        int pos = now.first;
        int t = now.second;
        if(t == g) {
            if(chmin(dp[pos][0], dp[pos][t] + 1)) {
                deq.push_back({pos, 0});
                continue;
            }
        } else {
            if(pos > 0) {
                int to = t + d[pos] - d[pos-1];
                if(to <= g) {
                    if(chmin(dp[pos-1][to], dp[pos][t])) {
                        deq.push_front({pos-1, to});
                    }
                }
            }
            if(pos < M - 1) {
                int to = t + d[pos+1] - d[pos];
                if(to <= g) {
                    if(chmin(dp[pos+1][to], dp[pos][t])) {
                        deq.push_front({pos+1, to});
                    }
                }
            }
        }
    }
    ll ans = 1e18;
    for(ll i = 0; i <= g; i++) {
        if(dp[M-1][i] == 1e18) continue;
        ll tmp = dp[M-1][i] * (r + g) + i;
        chmin(ans, tmp);
    }
    if(ans == 1e18) ans = -1;
    cout << ans << endl;
    return 0;
}