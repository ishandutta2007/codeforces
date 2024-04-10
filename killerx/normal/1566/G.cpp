#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int CNT = 0;

const int T = 150, mxn = 1e5 + 5, C = 2;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int n, m, q;
int col[mxn][T];
std::map <int, int> adj[mxn];
std::multiset <int> s3[mxn];
std::multiset <long long> ans3;
std::priority_queue <int, std::vector <int>, std::greater <int> > setI[T][C], setD[T][C];

long long query3(int u) {
    if (s3[u].size() < 3) return 1LL << 60;
    long long ans = 0;
    int cnt = 3;
    for (auto it = s3[u].begin(); it != s3[u].end() && cnt --; ++ it) {
        ans += *it;
    }
    return ans;
}

void add(int u, int v, int w) {
    ans3.erase(ans3.find(query3(u)));
    ans3.erase(ans3.find(query3(v)));
    adj[u][v] = w;
    s3[u].insert(w);
    s3[v].insert(w);
    rep(t, T) if (col[u][t] == col[v][t]) ++ CNT, setI[t][col[u][t]].push(w);
    ans3.insert(query3(u));
    ans3.insert(query3(v));
}

void del(int u, int v) {
    ans3.erase(ans3.find(query3(u)));
    ans3.erase(ans3.find(query3(v)));
    int w = adj[u][v];
    adj[u].erase(v);
    s3[u].erase(s3[u].find(w));
    s3[v].erase(s3[v].find(w));
    rep(t, T) if (col[u][t] == col[v][t]) ++ CNT, setD[t][col[u][t]].push(w);
    ans3.insert(query3(u));
    ans3.insert(query3(v));
}

int top(int t, int u) {
    while (setI[t][u].top() == setD[t][u].top()) {
        setI[t][u].pop();
        setD[t][u].pop();
        ++ CNT;
    }
    int ans = setI[t][u].top();
    return ans;
}

long long calc() {
    long long ans = 1LL << 60;
    if (!ans3.empty()) ans = std::min(ans, *ans3.begin());
    rep(t, T) {
        {
            int a = 0, b = 1;
            ans = std::min(ans, 0LL + top(t, a) + top(t, b));
        }
    }
    return ans;
}

int main() {
    #ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    rep(t, T) rep(i, n) col[i][t] = std::uniform_int_distribution <int> (0, 1)(rng);
    rep(i, n) ans3.insert(1LL << 60);
    rep(t, T) rep(c, C) setI[t][c].push(2e9), setD[t][c].push(2e9 + 1);
    rep(i, m) {
        int u, v, w;
        std::cin >> u >> v >> w;
        -- u, -- v;
        if (u > v) std::swap(u, v);
        add(u, v, w);
    }
    std::cout << calc() << "\n";
    int q;
    std::cin >> q;
    while (q --) {
        int tp, u, v;
        std::cin >> tp >> u >> v;
        -- u, -- v;
        if (u > v) std::swap(u, v);
        if (tp == 0) {
            del(u, v);
        } else {
            int w;
            std::cin >> w;
            add(u, v, w);
        }
        std::cout << calc() << "\n";
    }
    // std::cerr << CNT << std::endl;
    return 0;
}