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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> p(n), c(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i], &c[i]);
            p[i]--;
            if (p[i] == -1) {
                assert(root == -1);
                root = i;
            }
        }
        assert(root != -1);

        vector<vector<int>> e(n);
        for (int i = 0; i < n; i++) {
            if (p[i] != -1) {
                e[p[i]].push_back(i);
            }
        }

        bool fail = 0;
        vector<int> ans(n);
        function<vector<int>(int)> dfs = [&](int v) {
            vector<int> res;
            for (int to : e[v]) {
                auto nw = dfs(to);
                if (fail) return vector<int>();
                for (int x : nw) res.push_back(x);
            }

            if (c[v] > (int)res.size()) {
                fail = 1;
                return vector<int>();
            }

            vector<vector<int>> b(res.size());
            for (int x : res) {
                assert(ans[x] < (int)b.size());
                b[ans[x]].push_back(x);
            }

            int curColor = 0;
            int cur = 0;
            for (int i = 0; i < (int)b.size(); i++) {
                for (int x : b[i]) {
                    if (cur == c[v]) ans[v] = curColor++;
                    ans[x] = curColor++;
                    cur++;
                }
            }
            if (cur == c[v]) ans[v] = curColor++;

            res.push_back(v);
            return res;
        };
        dfs(root);
        if (fail) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
        }
    }

    return 0;
}