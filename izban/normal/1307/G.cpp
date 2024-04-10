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
#include <numeric>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL

static struct __timestamper {
    string what;

    __timestamper(const char *what) : what(what) {};

    __timestamper(const string &what) : what(what) {};

    ~__timestamper() {
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");

#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef double dbl;


bool eq(dbl x, dbl y) {
    return fabs(x - y) < 1e-9;
}

bool ls(dbl x, dbl y) {
    return x < y && !eq(x, y);
}

vector<double> simplex(vector<vector<double> > a) {
    int n = a.size() - 1;
    int m = a[0].size() - 1;
    vector<int> left(n + 1), up(m + 1);
    iota(up.begin(), up.end(), 0);
    iota(left.begin(), left.end(), m);
    auto pivot = [&](int x, int y) {
        swap(left[x], up[y]);
        double k = a[x][y];
        a[x][y] = 1;
        vector<int> vct;
        for (int j = 0; j <= m; j++) {
            a[x][j] /= k;
            if (!eq(a[x][j], 0)) vct.push_back(j);
        }
        for (int i = 0; i <= n; i++) {
            if (eq(a[i][y], 0) || i == x) continue;
            k = a[i][y];
            a[i][y] = 0;
            for (int j : vct) a[i][j] -= k * a[x][j];
        }
    };
    while (1) {
        int x = -1;
        for (int i = 1; i <= n; i++) if (ls(a[i][0], 0) && (x == -1 || a[i][0] < a[x][0])) x = i;
        if (x == -1) break;
        int y = -1;
        for (int j = 1; j <= m; j++) if (ls(a[x][j], 0) && (y == -1 || a[x][j] < a[x][y])) y = j;
        if (y == -1) assert(0); // infeasible
        pivot(x, y);
    }
    while (1) {
//        for (auto v : a) {
//            dbv(v);
//        }
        int y = -1;
        for (int j = 1; j <= m; j++) if (ls(0, a[0][j]) && (y == -1 || a[0][j] > a[0][y])) y = j;
        if (y == -1) break;
//        db(y);
        int x = -1;
        for (int i = 1; i <= n; i++) if (ls(0, a[i][y]) && (x == -1 || a[i][0] / a[i][y] < a[x][0] / a[x][y])) x = i;
//        db(x);
        if (x == -1) assert(0); // unbounded
        pivot(x, y);
    }
    vector<double> ans(m + 1);
    for (int i = 1; i <= n; i++) if (left[i] <= m) ans[left[i]] = a[i][0];
    ans[0] = -a[0][0];
    return ans;
}
// j=1..m: x[j]>=0
// i=1..n: sum(j=1..m) A[i][j]*x[j] <= A[i][0]
// max sum(j=1..m) A[0][j]*x[j]
// res[0] is answer
// res[1..m] is certificate

void print(vector<double> v) {
    for (auto x : v) printf("%.17f\n", x);
}



// old code reused

const int N = 205, M = N*N << 1;

int n, m, p, s, t;

int top, head[N], to[M], nxt[M], c[M], l[M];

void addedge(int u, int v, int cap, int len) {
    to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] =
            top++;
}

vector<pair<int, int >> paths;

int dis[N], fa[N];

bool inque[N];

const int INF = 1000000000;

bool go(int source, int target) {
    for (int i = 0; i < n; ++i) {
        dis[i] = INF;
    }
    dis[source] = 0;
    inque[source] = true;
    queue<int> q;
    q.push(source);
    while (q.size()) {
        int u = q.front();
        inque[u] = false;
        q.pop();
        for (int i = head[u]; ~i; i = nxt[i]) {
            if (c[i]) {
                int v = to[i], nd = dis[u] + l[i];
                if (dis[v] > nd) {
                    dis[v] = nd;
                    fa[v] = i;
                    if (!inque[v]) {
                        inque[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    if (dis[target] == INF) {
        return false;
    }
    int f = INF;
    int u = target;
    while (u != source) {
        int e = fa[u];
        f = min(f, c[e]);
        u = to[e ^ 1];
    }
    paths.push_back(make_pair(f, dis[target]));
    u = target;
    while (u != source) {
        int e = fa[u];
        c[e] -= f, c[e ^ 1] += f;
        u = to[e ^ 1];
    }
    return true;
}

struct Edge {
    int from, to, w;
};

vector<double> solve(int _n, vector<Edge> ed, vector<int> q) {
    int m = ed.size();


    n = _n;

    s = 0;
    t = n -1;

    top = 0;
    memset (head, -1, sizeof (head));
    for (auto o : ed) {
        addedge (o.from, o.to, 1, o.w);
        addedge (o.to, o.from, 0, -o.w);
    }


    while (go (s, t))
    {
        continue;
    }

    vector<double> res;
    for (auto p : q) {
        int csum = 0, fsum = 0;
        for (int i = 0; i < (int) paths.size(); ++i) {
            csum += paths[i].first * paths[i].second;
            fsum += paths[i].first;
            double ans = (double) (p + csum) / fsum;
            if (i + 1 == paths.size() || ans < paths[i + 1].second) {
                res.push_back(ans);
                break;
            }
        }
    }
    return res;
}


void test() {
    mt19937 rnd;

    int n = 50;
    vector<Edge> ed;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ed.push_back({i, j, rnd() % (int) 1e2});
            }
        }
    }
    vector<int> x;
    for (int i = 0; i < 1e5; i++) x.push_back(i);

    auto res = solve(n, ed, x);
    print(res);
    exit(0);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

//    test();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<Edge> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ed[i].from, &ed[i].to, &ed[i].w);
            ed[i].from--;
            ed[i].to--;
        }
        int q;
        scanf("%d", &q);
        vector<int> b(q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &b[i]);
        }

        print(solve(n, ed, b));
    }

    return 0;
}