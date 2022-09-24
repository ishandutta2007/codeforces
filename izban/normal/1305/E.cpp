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

int cnt(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt += binary_search(a.begin(), a.end(), a[i] + a[j]);
        }
    }
    return cnt;
}

void work() {
    vector<int> cur;
    for (int n = 1; n <= 100; n++) {
        cur.push_back(n);
        int w = cnt(cur);
        db2(n, w);
    }
    exit(0);
}

vector<int> solve(int n, int m) {
    vector<int> ans;

    ll ways = 0;
    for (int i = 1;; i++) {
        ll nways = ways + (i - 1) / 2;
        if (nways >= m) break;
        ans.push_back(i);
        ways = nways;
    }

    if ((int)ans.size() >= n) {
        return vector<int>();
    }

    int taken = ans.empty() ? 0 : ans.back();

    for (int nw = taken + 1;; nw++) {
        // 1 <= i
        // i < nw - i
        // nw - i <= taken

        // 2 * i < nw
        // i >= nw - taken

        int mx = (nw - 1) / 2;
        int mn = nw - taken;

        if (ways + max(0, mx - mn + 1) == m) {
            ans.push_back(nw);
            break;
        }
    }


    int need = n - (int)ans.size();
    assert(need >= 0);
    int last = ans.back();
    for (int i = 0; i < need; i++) {
        ans.push_back(1e9 - (last + 1) * i);
    }
    sort(ans.begin(), ans.end());

#ifdef LOCAL
    assert(cnt(ans) == m);
#endif
    return ans;
}

void print(vector<int> v) {
    if (v.empty()) printf("%d\n", -1);
    else {
        for (int i = 0; i < (int)v.size(); i++) printf("%d%c", v[i], " \n"[i + 1 == (int)v.size()]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    work();
    if (0) {
        for (int n = 1; n <= 100; n++) {
            db(n);
            for (int m = 0; m <= 1000; m++) {
                solve(n, m);
            }
        }
    }

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        print(solve(n, m));
    }

    return 0;
}