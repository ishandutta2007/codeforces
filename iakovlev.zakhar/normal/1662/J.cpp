// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 130;

template<size_t N, typename T>
class max_flow {
public:
    class edge {
    public:
        int to;
        T cap, flow;

        edge(int _to, T _cap) : to(_to), cap(_cap), flow(T()) {} 
    };

    max_flow() {
        edges.reserve(2 * N);
    }

    void clear() {
        for (int i = 0; i < N; ++i) {
            g[i].clear();
        }
        edges.clear();
    }

    void reset_flow() {
        for (int i = 0; i < (int)edges.size(); ++i) {
            edges[i].flow = T();
        }
    }

    void add_edge(int from, int to, int cap) {
        g[from].push_back((int)edges.size());
        edges.push_back(edge(to, cap));
        g[to].push_back((int)edges.size());
        edges.push_back(edge(from, 0));
    }

    bool bfs(int s, int t) {
        memset(d, -1, sizeof(d));

        d[s] = 0;
        q[0] = s;
        int head = 0, tail = 1;
        while (head < tail) {
            int v = q[head++];
            for (auto i : g[v]) {
                auto&[to, cap, flow] = edges[i];
                if (d[to] == -1 && flow < cap) {
                    d[to] = d[v] + 1;
                    q[tail++] = to;
                }
            }
        }

        return d[t] != -1;
    }

    T dfs(int v, int t, T curPushed) {
        if (curPushed == T() || v == t) {
            return curPushed;
        }

        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int i = g[v][ptr[v]];
            auto&[to, cap, flow] = edges[i];
            if (d[to] != d[v] + 1 || cap == flow) {
                continue;
            }
            T pushed = dfs(to, t, std::min(curPushed, cap - flow));
            if (pushed != T()) {
                edges[i].flow += pushed;
                edges[i ^ 1].flow -= pushed;
                return pushed;
            }
        }

        return 0;
    }

    T find_max_flow(int s, int t) {
        T flow = T();

        while (bfs(s, t)) {
            memset(ptr, 0, sizeof(ptr));

            while (true) {
                T pushed = dfs(s, t, std::numeric_limits<T>::max() / 2);
                if (pushed == T()) {
                    break;
                }
                flow += pushed;
            }
        }

        return flow;
    }

    std::vector<int> g[N];
    std::vector<edge> edges;
    int d[N], q[N], ptr[N];
};

int a[N][N], c[N][N];
max_flow<2 * N * N, int> dinic;

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &c[i][j]);
        }
    }

    int s = 2 * N * N - 1;
    int t = 2 * N * N - 2;
    for (int i = 0; i < n; ++i) {
        for (int val = 1; val < n; ++val) {
            dinic.add_edge(n * i + val + 1, n * i + val, INF);
        }
        dinic.add_edge(s, n * i + 1, INF);
        dinic.add_edge(n * i + n, t, INF);
    }
    for (int j = 0; j < n; ++j) {
        for (int val = 1; val < n; ++val) {
            dinic.add_edge(n * (n + j) + val + 1, n * (n + j) + val, INF);
        }
        dinic.add_edge(s, n * (n + j) + 1, INF);
        dinic.add_edge(n * (n + j) + n, t, INF);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = a[i][j];

            int from = n * i + val;
            int to = n * (n + j) + val;
            dinic.add_edge(from, to, 1 - c[i][j]);

            if (val != 1) {
                dinic.add_edge(from, to - 1, INF);
            }
            if (val != n) {
                dinic.add_edge(to, from + 1, INF);
            }
        }
    }

    int ans = dinic.find_max_flow(s, t);
    printf("%d\n", n - ans);
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}