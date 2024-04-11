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

const long long INF = 1e9;
//const ll mod = 1000000007;
ll N, M;
ll ans = INF;
ll u[1000], v[1000];
struct max_flow {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};


void f(int now) {
    max_flow graph(2 * N + 2);
    int s = 2 * N;
    int t = 2 * N + 1;
    ll tmp = 2 * N - 1;
    ll m = M;
    for(int i = 0; i < M; i++) {
        if(u[i] == now or v[i] == now) {
            tmp--;
            m--;
        }
        else graph.add_edge(u[i], v[i] + N, 1);
    }
    for(int i = 0; i < N; i++) {
        if(i == now) continue;
        graph.add_edge(s, i, 1);
        graph.add_edge(i+N, t, 1);
    }
    ll num = graph.run(s, t);
    tmp += m - num;
    tmp += N - 1 - num;
    chmin(ans, tmp);
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    for(int i = 0; i < N; i++) {
        f(i);
    }
    cout << ans << endl;
    return 0;
}