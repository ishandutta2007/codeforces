#include <bits/stdc++.h>

#include <algorithm>

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

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
ll H, W;
vector<vector<ll>> a, idx, ansval;
vector<vector<char>> ansc;
ll dh[4] = {1, -1, 0, 0};
ll dw[4] = {0, 0, 1, -1};
string dir = "DURL";
void A(l_l from, l_l to) {
    for(int k = 0; k < 4; k++) {
        int newh = from.first + dh[k];
        int neww = from.second + dw[k];
        if(newh != to.first or neww != to.second) continue;
        ansc[from.first][from.second] = dir[k];
        return;
    }
    assert(0);
}
void solve() {
    cin >> H >> W;
    a.clear();
    idx.clear();
    ansval.clear();
    ansc.clear();
    a.resize(H, vector<ll>(W));
    idx.resize(H, vector<ll>(W));
    ansval.resize(H, vector<ll>(W));
    ansc.resize(H, vector<char>(W));
    map<ll, vector<l_l>> mp;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
            mp[a[i][j]].push_back({i, j});
        }
    }
    for(auto tmp : mp) {
        ll val = tmp.first;
        auto v = tmp.second;
        //cerr << "----" << val << "----" << v.size() << endl;
        for(int i = 0; i < v.size(); i++) {
            idx[v[i].first][v[i].second] = i;
        }
        ll dummy0 = v.size();
        ll dummy1 = dummy0 + 1;
        ll s = dummy1 + 1;
        ll t = s + 1;
        atcoder::mf_graph<ll> g(t + 1);
        for(int i = 0; i < v.size(); i++) {
            auto tmp = v[i];
            ll h = tmp.first;
            ll w = tmp.second;
            if((h+w) % 2 == 0) {
                g.add_edge(s, i, 1);
                g.add_edge(dummy1, t, 1);
                for(int k = 0; k < 4; k++) {
                    int newh = h + dh[k];
                    int neww = w + dw[k];
                    if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                    if(a[newh][neww] == val) {
                        g.add_edge(i, idx[newh][neww], 1);
                    }
                    if(a[newh][neww] < val) {
                        g.add_edge(i, dummy1, 1);
                    }
                }
            } else {
                g.add_edge(i, t, 1);
                g.add_edge(s, dummy0, 1);
                for(int k = 0; k < 4; k++) {
                    int newh = h + dh[k];
                    int neww = w + dw[k];
                    if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                    if(a[newh][neww] < val) {
                        g.add_edge(dummy0, i, 1);
                    }
                }
            }
        }
        g.add_edge(dummy0, dummy1, (ll)v.size());
        ll f = g.flow(s, t);
        //cerr << dummy0 << " " << dummy1 << " " << s << " " << t << endl;
        //cerr << val << " " << f << endl;
        /*
        auto tmp2 = g.edges();
        for(auto e : tmp2) {
            cerr << e.from << " " << e.to << " " << e.cap << endl;
        }
        */
        if(f != v.size()) {
            cout << "NO" << endl;
            return;
        }
        auto edges = g.edges();
        for(auto e : edges) {
            if(e.flow != 1) continue;
            if(0 <= e.from and e.from < v.size()) {
                if(0 <= e.to and e.to < v.size()) {
                    A(v[e.from], v[e.to]);
                    A(v[e.to], v[e.from]);
                    ansval[v[e.from].first][v[e.from].second] = 1;
                    ansval[v[e.to].first][v[e.to].second] = val - 1;
                } else if(e.to == dummy1) {
                    for(int k = 0; k < 4; k++) {
                        ll h = v[e.from].first;
                        ll w = v[e.from].second;
                        int newh = h + dh[k];
                        int neww = w + dw[k];
                        if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                        if(a[newh][neww] < val) {
                            A({h, w}, {newh, neww});
                            ansval[h][w] = val - a[newh][neww];
                            break;
                        }
                    }
                }
            } else if(0 <= e.to and e.to < v.size() and e.from == dummy0) {
                for(int k = 0; k < 4; k++) {
                    ll h = v[e.to].first;
                    ll w = v[e.to].second;
                    int newh = h + dh[k];
                    int neww = w + dw[k];
                    if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                    if(a[newh][neww] < val) {
                        A({h, w}, {newh, neww});
                        ansval[h][w] = val - a[newh][neww];
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(w != 0) cout << " ";
            cout << ansval[h][w];
        }
        cout << endl;
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(w != 0) cout << " ";
            cout << ansc[h][w];
        }
        cout << endl;
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}