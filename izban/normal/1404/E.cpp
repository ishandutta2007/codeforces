#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

const int INF = (int)1.01e9;

struct Edge {
    int to, cap, flow;
};

struct Graph {
    int n;
    vector<vector<int> > e;
    vector<Edge> edges;
    vector<int> d, c;

    Graph() {}
    Graph(int _n) {
        n = _n;
        e.resize(n);
    }

    void addEdge(int from, int to, int cap) {
        e[from].push_back(edges.size());
        edges.push_back(Edge({to, cap, 0}));
        e[to].push_back(edges.size());
        edges.push_back(Edge({from, 0, 0}));
    }

    bool bfs() {
        d.assign(n, INF);
        c.assign(n, 0);
        vector<int> q(n);
        int qL = 0, qR = 0;
        d[0] = 0;
        q[qR++] = 0;
        while (qL < qR) {
            int v = q[qL++];
            for (int i = 0; i < (int)e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + 1 && cur.flow < cur.cap) {
                    d[cur.to] = d[v] + 1;
                    q[qR++] = cur.to;
                }
            }
        }
        return d[n - 1] != INF;
    }

    int dfs(int v, int flow) {
        if (v == n - 1) return flow;
        if (flow == 0) return 0;
        for (int &i = c[v]; i < (int)e[v].size(); i++) {
            Edge cur = edges[e[v][i]];
            if (d[cur.to] != d[v] + 1) continue;
            int pushed = dfs(cur.to, min(flow, cur.cap - cur.flow));
            if (pushed > 0) {
                edges[e[v][i]].flow += pushed;
                edges[e[v][i] ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll flow() {
        ll flow = 0;
        while (bfs()) {
            while (int pushed = dfs(0, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int solve3(int n, int m, vector<string> a) {
    int comp1 = n * (m-1);
    int comp2 = n * m;
    int comp3 = (n-1) * m;
    Graph gr(1 + comp1 + comp2 + comp3 + 1);
    int positive = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            int vert = i * (m - 1) + j;
            if (a[i][j] == '#' && a[i][j + 1] == '#') {
                gr.addEdge(0, 1 + vert, 1);
            }
            int vert1 = i * m + j;
            int vert2 = i * m + (j + 1);
            gr.addEdge(1 + vert, 1 + comp1 + vert1, INF);
            gr.addEdge(1 + vert, 1 + comp1 + vert2, INF);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int vert = i * m + j;
            if (a[i][j] == '#' && a[i + 1][j] == '#') {
                gr.addEdge(1 + comp1 + comp2 + vert, 1 + comp1 + comp2 + comp3, 1);
                positive++;
            }
            int vert1 = i * m + j;
            int vert2 = (i + 1) * m + j;
            gr.addEdge(1 + comp1 + vert1, 1 + comp1 + comp2 + vert, INF);
            gr.addEdge(1 + comp1 + vert2, 1 + comp1 + comp2 + vert, INF);
        }
    }
    int ans = positive;
    ans -= gr.flow();
    return ans;
}


int solve2(int n, int m, vector<string> a) {
    int ans = 0;
    for (auto s : a) {
        for (int i =1 ; i < (int)s.length(); i++) {
            if (s[i] == '#' && s[i -1 ] == '#') {
                ans++;
            }
        }
    }
    ans += solve3(n, m, a);
    return ans;
}


int solve(int n, int m, vector<string> a) {
    int ans = 0;
    for (auto s : a) {
        for (auto c : s) {
            if (c == '#') ans++;
        }
    }
    ans -= solve2(n, m, a);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<string> a(n);
        for  (int i  = 0; i < n; i++) {
            static char buf[(int)1.01e6];
            scanf(" %s", buf);
            a[i] = buf;
        }

        printf("%d\n", solve(n, m, a));
    }

    return 0;
}