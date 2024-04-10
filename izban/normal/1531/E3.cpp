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

struct graph {
    int n;
    vector<vector<int>> e;

    graph(int _n) {
        n = _n;
        e.resize(n);
    }

    void addEdge(int u, int v) {
        e[u].push_back(v);
    }

    vector<int> topsort() const {
        vector<char> vis(n);
        vector<int> ans;
        bool cycle = 0;
        function<void(int)> dfs = [&](int v) {
            vis[v] = 1;
            for (int to : e[v]) {
                if (vis[to] == 0) {
                    dfs(to);
                } else if (vis[to] == 1) {
                    cycle = 1;
                }
            }
            vis[v] = 2;
            ans.push_back(v);
        };
        for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
        reverse(ans.begin(), ans.end());
        if (cycle) return vector<int>();
        return ans;
    }
};

pair<int, vector<int>> solve(string s, int n) {
    int cur = 0;
    function<int(int, int)> est = [&](int l, int r) {
        if (r - l <= 1) return 0;
        int m = (l + r) >> 1;
        auto v1 = est(l, m);
        if (v1 != 0) return v1;
        auto v2 = est(m, r);
        if (v2 != 0) return v2;

        int i = l;
        int j = m;
        while (i < m && j < r) {
            if (cur == s.length()) {
                cur++;
                return -1;
            }
            if (s[cur++] == '0') {
                i++;
            } else {
                j++;
            }
        }
        return 0;
    };
    auto v = est(0, n);
    if (v != 0) return make_pair(v, vector<int>());
    if (cur != s.size()) return make_pair(1, vector<int>());

    cur = 0;

    graph g(n);
    function<pair<int, vector<int>>(int, int)> rec = [&](int l, int r) {
        if (r - l == 1) {
            return make_pair(0, vector<int>{l});
        }
        if (r - l == 0) return make_pair(0, vector<int>{});

        int m = (l + r) >> 1;
        auto v1 = rec(l, m);
        if (v1.first != 0) return v1;
        auto v2 = rec(m, r);
        if (v2.first != 0) return v2;

        vector<int> res;
        int i = l;
        int j = m;
        while (i < m && j < r) {
            if (cur == s.length()) {
                return make_pair(-1, vector<int>());
            }
            if (s[cur++] == '0') {
                g.addEdge(v1.second[i - l], v2.second[j - m]);
                res.push_back(v1.second[i - l]);
                i++;
            } else {
                g.addEdge(v2.second[j - m], v1.second[i - l]);
                res.push_back(v2.second[j - m]);
                j++;
            }
        }
        while (i < m) res.push_back(v1.second[i++ - l]);
        while (j < r) res.push_back(v2.second[j++ - m]);

        return make_pair(0, res);
    };
    auto o = rec(0, n);
    int ok = o.first;

    pair<int, vector<int>> res = {ok, vector<int>()};
    if (res.first == 0 && cur != s.length()) res = make_pair(1, vector<int>());
    if (res.first != 0) return res;

    res.second = g.topsort();
    if (res.second.empty()) res.first = -2;

    return res;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        mt19937 rnd;

        int L = s.length() / 17;
        int R = s.length() * 3;
        while (1) {
            int n = (L + R) / 2;
//            n = 16;
            auto v = solve(s, n);
//            cerr << n << " " << L << " " << R << " " << v.first << endl;
            if (v.first == 0) {
                vector<int> ov(n);
                for (int i = 0; i < n; i++) ov[v.second[i]] = i;
                v.second = ov;

                cout << n << endl;
                for (int x : v.second) cout << x + 1 << " ";
                cout << endl;
                break;
            }
//            return 0;
            if (v.first == -1) R = n;
            if (v.first == 1) L = n;
        }
    }

    return 0;
}