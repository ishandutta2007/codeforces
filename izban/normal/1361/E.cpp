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

const int NOT_FOUND = -2;
const int BAD = -1;

struct segtree {
    int n, N;
    vector<vector<int>> a, t;
    segtree(const vector<vector<int>> &_a) {
        a = _a;
        n = a.size();
        N = 1;
        while (N < n) N <<= 1;

        t.resize(2 * N);
        for (int i = 0; i < n; i++) {
            sort(a[i].begin(), a[i].end());
            t[N + i] = a[i];
        }
        for (int v = N - 1; v > 0; v--) {
            t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
            merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
        }
    }


    int Merge(int cans, int v, int need) {
        if (cans == BAD) return BAD;
        int id = lower_bound(t[v].begin(), t[v].end(), need) - t[v].begin();
        if (id == 0) return cans;
        if (id > 1) return BAD;
        if (cans == NOT_FOUND) return t[v][0];
        return BAD;
    }

    int get(int l, int r, int x) {
        l += N;
        r += N;
        int ans = NOT_FOUND;
        while (l <= r) {
            if (l & 1) ans = Merge(ans, l, x);
            if (!(r & 1)) ans = Merge(ans, r, x);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return ans;
    }
};

vector<int> solve(vector<vector<int>> e) {
    int n = e.size();
    vector<int> ans;
    mt19937 rnd(2314532534);
    for (int it = 0; it < 65; it++) {
        int root = rnd() % n;

        bool ok = 1;
        vector<int> c(n);
        vector<int> in(n, -1), out(n);
        vector<vector<int>> up(n);
        vector<int> par(n, -1);
        vector<int> vct;

        int tmr = 0;
        function<void(int)> dfs = [&](int v) {
            in[v] = tmr++;
            vct.push_back(v);
            c[v] = 1;
            for (int to : e[v]) {
                if (c[to] == 0) {
                    par[to] = v;
                    dfs(to);
                } else if (c[to] == 1) {
                    up[in[v]].push_back(in[to]);
                } else {
                    ok = 0;
                }
            }
            c[v] = 2;
            out[v] = tmr;
        };
        dfs(root);
        for (int i = 0; i < n; i++) ok &= in[i] != -1;
        if (!ok) continue;

        segtree tr(up);
        vector<int> good_pr(n);
        for (int v = 0; v < n; v++) {
            if (v == root) good_pr[v] = v;
            else {
                good_pr[v] = tr.get(in[v], out[v] - 1, in[v]);
                if (good_pr[v] < 0) good_pr[v] = -1;
                else good_pr[v] = vct[good_pr[v]];
            }
        }

        for (int i = 1; i < n; i++) {
            int v = vct[i];
            if (good_pr[v] != -1 && good_pr[good_pr[v]] == -1) {
                good_pr[v] = -1;
            }
        }
        for (int i = 0; i < n; i++) if (good_pr[i] != -1) ans.push_back(i);
        break;
    }
    if (ans.size() * 10 < 2 * n) ans.clear();
    return ans;
}

vector<int> slow(vector<vector<int>> e) {
    int n = e.size();
    vector<int> ans;

    for (int root = 0; root < n; root++) {
        bool ok = 1;
        vector<int> c(n);
        vector<int> in(n, -1), out(n);
        vector<vector<int>> up(n);
        vector<int> par(n, -1);
        vector<int> vct;

        int tmr = 0;
        function<void(int)> dfs = [&](int v) {
            in[v] = tmr++;
            vct.push_back(v);
            c[v] = 1;
            for (int to : e[v]) {
                if (c[to] == 0) {
                    par[to] = v;
                    dfs(to);
                } else if (c[to] == 1) {
                    up[in[v]].push_back(in[to]);
                } else {
                    ok = 0;
                }
            }
            c[v] = 2;
            out[v] = tmr;
        };
        dfs(root);
        for (int i = 0; i < n; i++) ok &= in[i] != -1;
        if (!ok) continue;
        ans.push_back(root);
    }
    if (ans.size() * 10 < 2 * n) ans.clear();
    return ans;
}

void stress() {
    for (int it = 1090;; it++) {
        mt19937 rnd(it);
        db(it);


        int n = rnd() % 10 + 1;
        vector<vector<int>> e(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <n; j++) {
                if (j != i && rnd() % 2) {
                    e[i].push_back(j);
                }
            }
        }
        auto ans1 = solve(e);
        auto ans2 = slow(e);
        if (ans1 != ans2) {
            dbv(ans1);
            dbv(ans2);
            db(n);
            for (auto neib : e) {
                dbv(neib);
            }
            exit(0);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    stress();

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> e(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
        }


        auto ans = solve(e);
        if (ans.size() * 10 < 2 * n) {
            printf("%d\n", -1);
        } else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i] + 1, " \n"[ i+ 1 == (int)ans.size()]);
        }
    }

    return 0;
}