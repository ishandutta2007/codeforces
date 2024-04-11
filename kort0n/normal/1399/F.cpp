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
int l[3005], r[3005];
vector<int> query[10000];
int dp[6050][6050];

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i <= 2 * N; i++) {
        for(int j = 0; j <= 2 * N; j++) {
            dp[i][j] = 0;
        }
        query[i].clear();
    }
    vector<ll> cmp;
    for(int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        cmp.push_back(l[i]);
        cmp.push_back(r[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), l[i]);
        l[i] = itr - cmp.begin();
        itr = lower_bound(cmp.begin(), cmp.end(), r[i]);
        r[i] = itr - cmp.begin();
        r[i]++;
        query[l[i]].push_back(i);
        //cerr << "{" << l[i] << ", " << r[i] << "}" << endl;
    }
    int ans = 0;
    for(int l = 1; l <= 2 * N; l++) {
        for(int i = 0; i <= 2 * N; i++) {
            ll j = i + l;
            if(j > 2 * N) continue;
            chmax(dp[i][j], dp[i+1][j]);
            chmax(dp[i][j], dp[i][j-1]);
            bool exist = false;
            for(auto idx : query[i]) {
                if(r[idx] == j) {
                    exist = true;
                }
                chmax(dp[i][j], dp[i][r[idx]] + dp[r[idx]][j]);
            }
            if(exist) dp[i][j]++;
            //cerr << i << " " << j << " " << dp[i][j] << endl;
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