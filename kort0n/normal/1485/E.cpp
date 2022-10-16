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
vector<ll> edges[201000];
ll depth[201000];
ll a[201000];
ll p[201000];
void dfs(int now) {
    for(auto to : edges[now]) {
        if(to == p[now]) continue;
        depth[to] = depth[now] + 1;
        p[to] = now;
        dfs(to);
    }
}

ll D;
map<ll, vector<ll>> mp;
ll dp[201000];

void solve() {
    ll N;
    cin >> N;
    mp.clear();
    for(int i = 0; i < N; i++) edges[i].clear(), dp[i] = 0;
    for(int i = 1; i < N; i++) {
        ll b;
        cin >> b;
        b--;
        edges[b].push_back(i);
        edges[i].push_back(b);
    }
    for(int i = 1; i < N; i++) cin >> a[i];
    p[0] = -1;
    dfs(0);
    for(int i = 0; i < N; i++) {
        mp[depth[i]].push_back(i);
    }
    D = mp.size();
    for(int d = 1; d < D; d++) {
        //cerr << "---------" << d << "--------" << endl;
        vector<ll> v;
        for(auto tmp : mp[d]) {
            chmax(dp[tmp], dp[p[tmp]]);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), [&](ll q, ll w){
            return a[q] < a[w];
        });
        for(auto tmp : v) {
            chmax(dp[tmp], dp[p[tmp]] + abs(a[tmp] - a[v[0]]));
            chmax(dp[tmp], dp[p[tmp]] + abs(a[tmp] - a[v.back()]));
        }
        ll val = -INF;
        for(auto tmp : v) {
            //cerr << tmp << " " << val << endl;
            chmax(dp[tmp], val + a[tmp]);
            chmax(val, dp[p[tmp]] - a[tmp]);
        }
        reverse(v.begin(), v.end());
        val = -INF;
        for(auto tmp : v) {
            chmax(dp[tmp], val - a[tmp]);
            chmax(val, dp[p[tmp]] + a[tmp]);
        }
        for(auto tmp : v) {
            //cerr << tmp << " " << dp[tmp] << endl;
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        cerr << i << " " << a[i] << endl;
        for(auto c : edges[i]) {
            if(c != p[i]) cerr << c << " ";
        }
        cerr << endl;
        cerr << endl;
    }
    */
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        chmax(ans, dp[i]);
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