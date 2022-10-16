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
ll N;
vector<ll> a;

ll dp[3005][3005];

int main() {
    cin >> N;
    a.resize(N);
    vector<ll> cmp;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] += N - i;
        cmp.push_back(a[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    int K = cmp.size();
    for(int i = 0; i < K; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i < N; i++) {
        ll before = INF;
        for(int j = 0; j < K; j++) {
            ll tmp = abs(a[i] - cmp[j]);
            chmin(before, dp[i][j]);
            dp[i+1][j] = before + tmp;
        }
    }
    ll ans = INF;
    for(int i = 0; i < K; i++) {
        chmin(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}