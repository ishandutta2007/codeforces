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


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }


        /*vector<int> d(n, -1); // distance to cycle
        vector<int> cid(n, -1); // cycle id
        vector<int> used(n, 0); // 0, 1, 2
        int cycles = 0;
        vector<int> ans(n, -1);
        vector<int> pans(n, -1);
        int empty = -1;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;

            vector<int> vct;
            int v = i;
            while (!used[v]) {
                vct.push_back(v);
                used[v] = 1;
                v = a[v];
            }

            if (used[v] == 1) {
                cycles++;
                while (used[v] == 1) {
                    used[v] = 2;
                    cid[v] = cycles - 1;
                    d[v] = 0;
                    ans[v] = a[v];
                    pans[a[v]] = v;
                    v = a[v];
                }
                if (empty == -1) {
                    empty = pans[v];
                    ans[v] = -1;
                    pans[a[v]] = -1;
                }
            }
            int cycle = cid[v];
            assert(cycle != -1);

            while (!vct.empty() && used[vct.back()] == 2) {
                vct.pop_back();
            }

            for (int j = 0; j < (int)vct.size(); j++) {
                int v = vct[(int)vct.size() - 1 - j];
                used[v] = 2;
                cid[v] = cycle;
                d[v] = d[a[v]] + 1;
            }
        }

        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return d[i] > d[j];
        });

        vector<int> rem;
        vector<char> cycle_used(cycles);
        for (int s : perm) {
            if (cycle_used[cid[s]]) {
                if (ans[s] == -1) {
                    rem.push_back(s);
                }
            } else {
                int v = s;
                int prev = -1;
                while (ans[v] == -1) {
                    ans[v] = a[v];
                    prev = v;
                    v = a[v];
                }
                ans[prev] = s;
                cycle_used[cid[s]] = 1;
            }
        }

        if (!rem.empty()) {
            int any_bad = -1;
            for (int i = 0; i < n; i++) {
                if (ans[i] != -1 && ans[i] != a[i]) {
                    any_bad = i;
                }
            }
            assert(any_bad != -1);
            int to = ans[any_bad];
            int cur = any_bad;
            for (int i = 0; i < (int)rem.size(); i++) {
                ans[cur] = rem[i];
                cur = rem[i];
            }
            ans[cur] = to;
        }*/

        vector<int> indeg(n);
        for (int x : a) indeg[x]++;

        vector<int> ans(n, -1);
        vector<int> pans(n, -1);
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return indeg[i] < indeg[j];
        });

        vector<int> no_out;
        vector<int> no_in;

        for (int v : perm) {
            if (ans[v] != -1) continue;
            if (indeg[v] == 0) {
                no_in.push_back(v);
            }
            int x = v;
            for (; pans[a[x]] == -1; x = a[x]) {
                ans[x] = a[x];
                pans[ans[x]] = x;
            }
            if (ans[v] == -1) {
                no_out.push_back(x);
            }
        }
//        dbv(no_in);
//        dbv(no_out);
        assert(no_in.size() == no_out.size());
        for (int i = 0; i < (int)no_in.size(); i++) {
            ans[no_out[i]] = no_in[i];
        }

        if (1) {
            for (int i = 0; i < n; i++) assert(ans[i] != -1);
            assert(set<int>(ans.begin(), ans.end()).size() == n);
            assert(*min_element(ans.begin(), ans.end()) == 0);
            assert(*max_element(ans.begin(), ans.end()) == n - 1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += a[i] == ans[i];
        }
        printf("%d\n", res);
        for (int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
    }

    return 0;
}