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

const string ALICE = "Alice";
const string BOB = "Bob";

string solve(int a, int b, int da, int db, vector<vector<int>> e) {
    int n =e.size();
    if (db <= 2 * da) return ALICE;

    vector<int> h(n);
    function<void(int, int, int)> dfs = [&](int v, int pr, int ch) {
        h[v] = ch;
        for (int to : e[v]) {
            if (to == pr) continue;
            dfs(to, v, ch + 1);
        }
    };
    function<vector<int>(int)> get_d = [&](int root) {
        dfs(root, -1, 0);
        return h;
    };

    auto d1 = get_d(a);
    if (d1[b] <= da) return ALICE;

    int v = 0;
    for (int i = 1; i < n; i++) if (d1[i] > d1[v]) v = i;

    auto d2 = get_d(v);
    int len = *max_element(d2.begin(), d2.end());

    if (len <= 2 * da) return ALICE;
    return BOB;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b, da, db;
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        a--;
        b--;
        vector<vector<int>> e(n);
        for (int i= 0; i < n -1 ; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            v--; u--;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        printf("%s\n", solve(a, b, da, db, e).c_str());
    }

    return 0;
}