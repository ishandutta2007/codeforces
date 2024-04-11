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
ll T;
ll N, M, K;
vector<int> edges[105000];
int d[105000];
set<int> rest;

vector<int> check(int v) {
    if(d[v] < K - 1) return {};
    assert(d[v] == K - 1);
    if(K * (K - 1) / 2 > M) return {};
    vector<int> ret;
    ret.push_back(v);
    for(auto u : edges[v]) {
        if(rest.find(u) != rest.end()) ret.push_back(u);
    }
    assert(ret.size() == K);
    for(int i = 0; i < ret.size(); i++) {
        for(int j = 0; j < i; j++) {
            assert(ret[i] != ret[j]);
            auto itr = lower_bound(edges[ret[i]].begin(), edges[ret[i]].end(), ret[j]);
            if(itr == edges[ret[i]].end() or *itr != ret[j]) return {};
        }
    }
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    rest.clear();
    for(int i = 0; i < N; i++) {
        d[i] = 0;
        edges[i].clear();
        rest.insert(i);
    }
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        d[u]++;
        d[v]++;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    priority_queue<i_i, vector<i_i>, greater<i_i>> que;
    for(int i = 0; i < N; i++) {
        sort(edges[i].begin(), edges[i].end());
        assert(d[i] == edges[i].size());
        if(d[i] < K) {
            que.push({d[i], i});
        }
    }
    while(!que.empty()) {
        i_i tmp = que.top();
        que.pop();
        int v = tmp.second;
        if(rest.find(v) == rest.end()) continue;
        auto ret = check(v);
        if(ret.empty()) {
            rest.erase(v);
            for(auto u : edges[v]) {
                d[u]--;
                if(d[u] < K) {
                    que.push({d[u], u});
                }
            }
            continue;
        } else {
            cout << 2 << endl;
            for(auto tmp : ret) {
                cout << tmp + 1 << " ";
            }
            cout << endl;
            return;
        }
    }
    if(rest.empty()) {
        cout << -1 << endl;
        for(int i = 0; i < N; i++) {
            assert(d[i] == 0);
        }
    } else {
        assert(rest.size() >= K + 1);
        cout << 1 << " " << rest.size() << endl;
        for(auto tmp : rest) {
            cout << tmp + 1 << " ";
            assert(d[tmp] >= K);
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) solve();
    return 0;
}