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
typedef pair<ll, l_l> lll;
vector<lll> edges[100500];
ll sz[100500];
vector<ll> v[2], sum[2];
void dfs(int now, int from) {
    sz[now] = 0;
    bool child = false;
    for(auto tmp : edges[now]) {
        ll to = tmp.first;
        if(to == from) continue;
        child = true;
        dfs(to, now);
        sz[now] += sz[to];
    }
    if(!child) sz[now] = 1;
    for(auto tmp : edges[now]) {
        ll to = tmp.first;
        if(to == from) continue;
        ll idx = tmp.second.second-1;
        ll copy = tmp.second.first;
        while(copy) {
            v[idx].push_back((copy - copy / 2) * sz[to]);
            copy /= 2;
        }
    }
}

void solve() {
    ll N, S;
    cin >> N >> S;
    for(int i = 0; i < 2; i++) v[i].clear(), sum[i].clear();
    for(int i = 0; i < N; i++) edges[i].clear();
    for(int i = 0; i < N - 1; i++) {
        ll a, b, w, c;
        cin >> a >> b >> w >> c;
        a--;
        b--;
        edges[a].push_back({b, {w, c}});
        edges[b].push_back({a, {w, c}});
    }
    dfs(0, -1);
    for(int i = 0; i < 2; i++) {
        sort(v[i].begin(), v[i].end(), greater<ll>());
        sum[i].push_back(0);
        for(int j = 0; j < v[i].size(); j++) {
            ll val = sum[i][j] + v[i][j];
            sum[i].push_back(val);
        }
    }
    ll ans = INF;
    S = sum[0].back() + sum[1].back() - S;
    //cerr << S << endl;
    for(int i = 0; i < sum[0].size(); i++) {
        auto itr = lower_bound(sum[1].begin(), sum[1].end(), S - sum[0][i]);
        if(itr == sum[1].end()) continue;
        chmin(ans, (ll)i + 2 * (itr - sum[1].begin()));
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