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

struct dsu {
    int n;
    vector<int> p;

    dsu(int _n) {
        n = _n;
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int get(int x) {
        if (x == p[x]) return x;
        return p[x] = get(p[x]);
    }

    void uni(int u, int v) {
        p[get(v)] = get(u);
    }

    void clear() {
        for (int i = 0; i < n; i++) p[i] = i;
    }
};

const int N = 1 << 21;
//dsu d(N);
vector<int> e[N];
vector<pair<int, int>> ed;
vector<char> used(ed.size());
vector<int> vct;

void dfs(int v) {
    while (1) {
        while (!e[v].empty() && used[e[v].back()]) {
            e[v].pop_back();
        }
        if (!e[v].empty()) {
            int id = e[v].back();
            used[id] = 1;
            int to = v ^ ed[id].first ^ ed[id].second;
            dfs(to);
            vct.push_back(v);
        } else break;
    }
}

void init(int n) {
    ed.clear();
    for (int i = 0; i < n; i++) {
        e[i].clear();
    }
}

void add_edge(int u, int v) {
    e[u].push_back(ed.size());
    e[v].push_back(ed.size());
    ed.push_back({u, v});
}

void solve(vector<int> a) {
    int N = a.size() + (1 << 20);

    auto solve = [&](int x) {
        int k = a.size();
        int n = k + (1 << x);
        init(n);

        for (int i = 0; i < k; i++) {
            add_edge(i, k + (a[i] & ((1 << x) - 1)));
        }
        for (int i = 0; i < k; i += 2) {
            add_edge(i, i + 1);
        }
        for (int i = 0; i < n; i++) {
            if (e[i].size() % 2 == 1) {
                return vector<int>();
            }
        }

        used.assign(ed.size(), 0);
        vct.clear();
        dfs(0);
        if (vct.size() != ed.size()) return vector<int>();

        vector<int> ans;
        for (int x : vct) if (x < k) ans.push_back(x);
        if (ans[0] / 2 != ans[1] / 2) rotate(ans.begin(), ans.begin() + 1, ans.end());

        assert(ans.size() == k);
        for (int i = 0; i < k; i++) {
            assert(ans[i] / 2 == ans[i ^ 1] / 2);
        }
        return ans;
    };

    int L = -1, R = 21;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (!solve(M).empty()) L = M;
        else R = M;
    }
    auto v = solve(L);
    printf("%d\n", L);
    for (int i = 0; i < (int)v.size(); i++) printf("%d%c", v[i] + 1, " \n"[i + 1 == (int)v.size()]);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(2 * n);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[2 * i], &a[2 * i + 1]);

        solve(a);
    }

    return 0;
}