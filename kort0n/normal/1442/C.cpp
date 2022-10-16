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
const ll mod = 998244353;
ll N, M;
vector<ll> edges[201000][2];
ll dp[55][201000];
l_l dist[201000];
bool visited[201000];
bool visits[55][201000];
const int MAX = 30;
typedef pair<ll, l_l> llll;
void f() {
    priority_queue<llll, vector<llll>, greater<llll>> que;
    for(int t = 0; t < MAX; t++) {
        for(int i = 0; i < N; i++) {
            visits[t][i] = false;
            if(dp[t][i] != INF) que.push({dp[t][i], {t, i}});
        }
    }
    while(!que.empty()) {
        auto tmp = que.top();
        que.pop();
        auto c = tmp.first;
        ll pos = tmp.second.second;
        ll nowt = tmp.second.first + dist[pos].first;
        ll idxt = tmp.second.first;
        if(visits[idxt][pos]) continue;
        visits[idxt][pos] = true;
        //cerr << pos << " " << nowt << "(" << idxt << ")" << c << endl;
        for(auto to : edges[pos][nowt%2]) {
            ll toidxt = (nowt - dist[to].first);
            if(toidxt >= MAX) continue;
            if(chmin(dp[toidxt][to], c+1)) {
                que.push({c+1, {toidxt, to}});
            }
        }
        for(auto to : edges[pos][(nowt + 1)%2]) {
            ll toidxt = (nowt + 1 - dist[to].first);
            if(toidxt >= MAX) continue;
            if(chmin(dp[toidxt][to], c+1)) {
                que.push({c+1, {toidxt, to}});
            }
        }
    }
}

bool ISLOW(l_l a, l_l b) {
    if(a.first >= 61 or b.first >= 61) {
        return a < b;
    }
    a.second += (1LL << a.first) - 1;
    b.second += (1LL << b.first) - 1;
    return a.second < b.second;
}

l_l minimum(vector<l_l> v) {
    assert(v.size() >= 1);
    auto now = v[0];
    for(int i = 1; i < v.size(); i++) {
        if(ISLOW(v[i], now)) now = v[i];
    }
    return now;
}

typedef pair<l_l, ll> lll;

void g() {
    for(int i = 0; i < N; i++) {
        dist[i] = {INF, INF};
        visited[i] = false;
    }
    dist[0] = {0, 0};
    priority_queue<lll, vector<lll>, greater<lll>> que;
    que.push({dist[0], 0});
    while(!que.empty()) {
        auto tmp = que.top();
        que.pop();
        ll now = tmp.second;
        l_l c = tmp.first;
        if(visited[now]) continue;
        visited[now] = true;
        for(auto to : edges[now][c.first%2]) {
            auto newc = c;
            newc.second++;
            if(chmin(dist[to], newc)) {
                que.push({newc, to});
            }
        }
        for(auto to : edges[now][1 - (c.first%2)]) {
            auto newc = c;
            newc.first++;
            newc.second++;
            if(chmin(dist[to], newc)) {
                que.push({newc, to});
            }
        }
    }
    for(int i = 0; i < N; i++) {
        auto tmp = dist[i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a][0].push_back(b);
        edges[b][1].push_back(a);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < MAX; j++) {
            dp[j][i] = INF;
        }
    }
    g();
    for(int i = 0; i < N; i++) {
        dp[0][i] = dist[i].second;
    }
    f();
    vector<l_l> candidates;
    for(int t = 0; t < MAX; t++) {
        if(dp[t][N-1] == INF) continue;
        candidates.push_back({t + dist[N-1].first, dp[t][N-1]});
    }
    l_l tmpans = minimum(candidates);
    ll ans = tmpans.second % mod;
    {
        ll tmp = 1;
        while(tmpans.first--) {
            tmp *= 2;
            tmp %= mod;
        }
        ans += tmp + mod - 1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}