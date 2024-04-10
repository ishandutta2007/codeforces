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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<int, int>> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &ed[i].first, &ed[i].second);
            ed[i].first--;
            ed[i].second--;
        }
        int k;
        scanf("%d", &k);
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        vector<vector<int>> e(n), g(n);
        for (auto o : ed) {
            e[o.first].push_back(o.second);
            g[o.second].push_back(o.first);
        }

        const int INF = 1e9;
        auto bfs = [&](int s) {
            vector<int> d(n, INF);
            d[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int to : g[v]) {
                    if (d[to] > d[v] + 1) {
                        d[to] = d[v] + 1;
                        q.push(to);
                    }
                }
            }
            return d;
        };
        auto d = bfs(a.back());

        int mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            int cnt = 0;
            for (int to : e[a[i]]) {
                if (d[to] + 1 == d[a[i]]) {
                    cnt++;
                }
            }
            if (d[a[i + 1]] + 1 != d[a[i]]) {
                mn++;
            }

            if (d[a[i + 1]] + 1 == d[a[i]]) {
                cnt--;
            }
            if (cnt > 0) {
                mx++;
            }
        }
        cout << mn << " " << mx << endl;
    }

    return 0;
}