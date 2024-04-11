#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int N;
vector<l_l> paths[201000];
ll SIZE[201000];
l_l minimize(ll now, ll from) {
    l_l ret = {0, 1};
    SIZE[now] = 1;
    for(int i = 0; i < paths[now].size(); i++) {
        int to = paths[now][i].first;
        ll cost = paths[now][i].second;
        if(to == from) continue;
        l_l tmp = minimize(to, now);
        SIZE[now] += SIZE[to];
        ret.first += tmp.first;
        ret.second += tmp.second;
        if(tmp.second) ret.first += cost;
    }
    ret.second %= 2;
    return ret;
}

int gravity;

void search() {
    for(int i = 0; i < paths[gravity].size(); i++) {
        int to = paths[gravity][i].first;
        if(SIZE[gravity] < SIZE[to]) continue;
        if(SIZE[to] >= N / 2) {
            gravity = to;
            search();
            return;
        }
    }
    return;
}

l_l maximize(ll now, ll from) {
    l_l ret = {0, 1};
    for(int i = 0; i < paths[now].size(); i++) {
        int to = paths[now][i].first;
        ll cost = paths[now][i].second;
        if(to == from) continue;
        l_l tmp = maximize(to, now);
        ret.first += tmp.second * cost;
        ret.second += tmp.second;
        ret.first += tmp.first;
    }
    //cerr << now << " " << ret.first << " " << ret.second << endl;
    return ret;
}

void solve() {
    cin >> N;
    N *= 2;
    for(int i = 1; i <= N; i++) {
        paths[i].clear();
        SIZE[i] = 0;
    }
    for(int i = 1; i < N; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        paths[u].emplace_back(v, w);
        paths[v].emplace_back(u, w);
    }
    cout << minimize(1, -1).first << " ";
    gravity = 1;
    search();
    for(int i = 1; i <= N; i++) {
        //cerr << SIZE[i] << " ";
    }
    //cerr << endl;
    //cerr << gravity << endl;
    cout << maximize(gravity, -1).first << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}