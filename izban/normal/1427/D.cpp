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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        vector<vector<int>> ans;
        auto op = [&](vector<int> v) {
            if (v.size() == 1) {
                assert(v[0] == n);
                return;
            }

            ans.push_back(v);

            vector<vector<int>> b(v.size());
            int cur =0 ;
            for (int i = 0; i < (int)v.size(); i++) {
                int x = v[i];
                while (x--) {
                    b[i].push_back(a[cur++]);
                }
            }
            assert(cur == n);

            reverse(b.begin(), b.end());
            a.clear();
            for (auto cv : b) a.insert(a.end(), cv.begin(), cv.end());
        };

        for (int i = 0; i < n - 1 - i; i++) {
            int p1 = -1, p2 = -1;
            for (int j = i; j <= n - 1 - i; j++) {
                if (a[j] == i) p1 =  j;
                if (a[j] == n - 1 - i) p2 = j;
            }
            assert(p1 != -1 && p2 != -1);

            int l = min(p1, p2);
            int r = max(p1, p2);

            vector<int> cop;
            for (int j = 0; j < i; j++) cop.push_back(1);
            cop.push_back(l - i + 1);
            if (l + 1 != r) {
                cop.push_back(r - l - 1);
            }
            cop.push_back(n - 1 - i - r + 1);
            for (int j = 0; j < i; j++) cop.push_back(1);
            op(cop);

            if (p1 < p2) {
                cop.assign(n, 1);
                op(cop);
            } else {
                cop.clear();
                for  (int j = 0; j < i; j++) cop.push_back(1);
                cop.push_back(n - 2 * i);
                for  (int j = 0; j < i; j++) cop.push_back(1);
                op(cop);
            }
        }

//        dbv(a);
        for (int i = 0; i < n; i++) assert(a[i] == i);
        assert(ans.size() <= n);

        printf("%d\n", (int)ans.size());
        for (auto v: ans) {
            printf("%d", (int)v.size());
            for (int x : v) printf(" %d", x);
            printf("\n");
        }
    }

    return 0;
}