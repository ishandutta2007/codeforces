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
vector<ll> paths[201000];
ll dist[201000];
void dfs(ll now, ll from) {
    for(auto to : paths[now]) {
        if(to == from) continue;
        dist[to] = dist[now] + 1;
        dfs(to, now);
    }
}
ll num[2];

int main() {
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
    for(int i = 0; i < N; i++) {
        num[dist[i] & 1]++;
    }
    ll ans = min(num[0], num[1]) - 1;
    cout << ans << endl;
    return 0;
}