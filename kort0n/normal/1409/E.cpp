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
ll dp[210000][3];

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x;
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
    }
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        x.push_back(a);
    }
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
    }
    sort(x.begin(), x.end());
    queue<ll> que;
    for(int i = 0; i < N; i++) {
        que.push(x[i]);
        while(que.front() < x[i] - K) que.pop();
        ll j = i - que.size();
        for(int k = 0; k < 2; k++) {
            chmax(dp[i+1][k+1], dp[j+1][k] + (ll)que.size());
        }
        for(int k = 0; k <= 2; k++) {
            chmax(dp[i+1][k], dp[i][k]);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= 2; j++) {
            chmax(ans, dp[i][j]);
        }
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