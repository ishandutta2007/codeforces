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
typedef long double ld;

#undef LOCAL

int n;
int queries;

vector<pair<int, int>> read() {
    queries = 0;
#ifdef LOCAL
#else
    cin >> n;
    vector<pair<int, int>> ed(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> ed[i].first >> ed[i].second;
        ed[i].first--;
        ed[i].second--;
    }
    return ed;
#endif
}

int ask(int x, int y) {
    queries++;
    assert(queries <= n / 2);
#ifdef LOCAL
#else
    cout << "? " << x+1 << " " << y+1 << endl;
    int res;
    cin >> res;
    res--;
    return res;
#endif
}

void ans(int x) {
#ifdef LOCAL
#else
    cout << "! " << x + 1 << endl;
#endif
}

void solve() {
    vector<pair<int, int>> ed = read();

    vector<vector<int>> e(n);
    for (auto o : ed) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }

    const int INF = 1e9;
    auto calc_dist = [&](int s) {
        vector<int> d(n, INF);
        vector<int> q;
        q.push_back(s);
        d[s] = 0;
        for (int i = 0; i < (int)q.size(); i++) {
            int v = q[i];
            for (int to : e[v]) {
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;
                    q.push_back(to);
                }
            }
        }
        return d;
    };

    auto del_edge = [&](int u, int v) {
        e[u].erase(find(e[u].begin(), e[u].end(), v));
        e[v].erase(find(e[v].begin(), e[v].end(), u));
    };

    int root = 0;
    while (!e[root].empty()) {
        if (e[root].size() == 1) {
            root = e[root][0];
        }
        if (e[root].size() == 1) {
            int w = ask(root, e[root][0]);
            root = w;
            break;
        }
        assert(e[root].size() >= 2);
        int c1 = e[root][0];
        int c2 = e[root][1];
        int w = ask(c1, c2);
        if (w == root) {
            del_edge(root, c1);
            del_edge(root, c2);
            continue;
        } else {
            del_edge(root, w);
            root = w;
            continue;
        }
    }
    ans(root);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}