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
typedef long double ld;

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

        const int SIGMA = 200;
        vector<vector<int>> vct(SIGMA);
        for (int i = 0; i < n; i++) {
            vct[a[i]].push_back(i);
        }

        vector<vector<int>> cnt(n + 1, vector<int>(SIGMA));
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            cnt[i + 1][a[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < SIGMA; i++) {
            ans = max(ans, (int)vct[i].size());
            for (int len = 1; len * 2 <= vct[i].size(); len++) {
                int L = vct[i][len - 1] + 1;
                int R = vct[i][(int)vct[i].size() - len] - 1;
                for (int c = 0; c < SIGMA; c++) {
                    ans = max(ans, len * 2 + cnt[R + 1][c] - cnt[L][c]);
                }
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}