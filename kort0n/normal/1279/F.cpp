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
ll N, K, L;
vector<ll> a, sum;
ll ans = 1e9;

vector<l_l> dp;
void f(ll mid) {
    for(int i = 0; i <= N; i++) dp[i] = {-1e9, 0};
    dp[0] = {0, 0};
    for(int i = 0; i < N; i++) {
        chmax(dp[i+1], dp[i]);
        ll to = min(i + L, N);
        l_l tmp = {dp[i].first + sum[to]-sum[i]-mid, dp[i].second + 1};
        chmax(dp[to], tmp);
    }
}

void solve() {
    dp.resize(N + 1);
    ll ok = 1e7;
    ll ng = -1e7;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        f(mid);
        if(dp[N].second <= K) ok = mid;
        else ng = mid;
    }
    f(ok);
    //cerr << ok << endl;
    //cerr << dp[N].first << " " << dp[N].second << endl;
    ll tmp = dp[N].first + ok * dp[N].second + (ok - 1) * (K - dp[N].second);
    chmin(ans, sum[N] - tmp);
    /*
    for(int i = 0; i <= N; i++) dp[i] = -1e9;
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        chmax(dp[i+1], dp[i]);
        ll to = min(N, i + L);
        chmax(dp[to], dp[i] + sum[to] - sum[i] - ok);
    }
    //ll tmp = sum[N] - dp[N] - ok * dp[N];
    ll tmp = sum[N] - dp[N];
    cerr << ok << " " << tmp << endl;
    f(ok);
    tmp -= ok * dp[N];
    //if(ok >= 1) tmp -= (K - dp[N]) * (ok - 1);
    cerr << ok << " " << tmp << " " << dp[N] << endl;
    chmin(ans, tmp);
    */
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K >> L;
    chmin(K, (N + L - 1) / L);
    a.resize(N);
    sum.resize(N+1);
    string S;
    cin >> S;
    for(int i = 0; i < N; i++) {
        if('a' <= S[i] and S[i] <= 'z') {
            a[i] = 1;
        }
        sum[i+1] = sum[i] + a[i];
    }
    solve();
    for(int i = 0; i <= N; i++) {
        sum[i] = i - sum[i];
    }
    solve();
    cout << ans << endl;
    return 0;
}