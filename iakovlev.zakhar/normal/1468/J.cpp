// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

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
const int N = 200100;

class Edge {
public:
    int from, to, cost;

    Edge() = default;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int p[N], sz[N];

void dsuInit(int n) {
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
}

int dsuGet(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = dsuGet(p[v]);
}

bool dsuUnite(int a, int b) {
    a = dsuGet(a);
    b = dsuGet(b);

    if (a == b) {
        return false;
    }
    if (sz[a] > sz[b]) {
        std::swap(a, b);
    }

    p[a] = b;
    sz[b] += sz[a];

    return true;
}

void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].cost);
        --edges[i].from;
        --edges[i].to;
    }

    std::sort(edges.begin(), edges.end());
    dsuInit(n);

    int it = 0; // first greater
    while (it < m && edges[it].cost <= k) {
        ++it;
    }

    ll ans = LINF;
    int cnt = 0;
    ll cost = 0;

    if (it != 0) {
        cost = k - edges[it - 1].cost;
        for (int i = it - 1; i >= 0; --i) {
            if (dsuUnite(edges[i].from, edges[i].to)) {
                ++cnt;
            }
        }

        if (cnt == n - 1) {
            ans = std::min(ans, cost);
        } else {
            cost = 0;
            for (int i = it; i < m; ++i) {
                if (cnt == n - 1) {
                    break;
                }

                if (dsuUnite(edges[i].from, edges[i].to)) {
                    ++cnt;
                    cost += edges[i].cost - k;
                }
            }
            ans = std::min(ans, cost);
        }
    }

    if (it == m) {
        assert(ans != LINF);
        printf("%lld\n", ans);
        return;
    }

    dsuInit(n);
    cost = edges[it].cost - k;
    cnt = 0;

    if (dsuUnite(edges[it].from, edges[it].to)) {
        ++cnt;
    } else {
        throw;
    }

    for (int i = it - 1; i >= 0; --i) {
        if (dsuUnite(edges[i].from, edges[i].to)) {
            ++cnt;
        }
    }

    for (int i = it + 1; i < m; ++i) {
        if (cnt == n - 1) {
            break;
        }

        if (dsuUnite(edges[i].from, edges[i].to)) {
            ++cnt;
            cost += edges[i].cost - k;
        }
    }

    assert(cnt == n - 1);
    ans = std::min(ans, cost);

    printf("%lld\n", ans);
}

void run() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }    
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