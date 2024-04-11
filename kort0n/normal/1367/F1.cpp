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

ll dp[201000];

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> cmp;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        cmp.push_back(a[i]);
    }
    for(int i = 0; i <= N; i++) dp[i] = 0;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), a[i]);
        a[i] = itr - cmp.begin();
    }
    for(int i = 0; i < N; i++) {
        chmax(dp[a[i]], dp[a[i]] + 1);
        if(a[i] > 0) {
            chmax(dp[a[i]], dp[a[i]-1] + 1);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        chmax(ans, dp[i]);
    }
    cout << N - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}