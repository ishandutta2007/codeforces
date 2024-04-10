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

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        int x, a, y, b;
        scanf("%d%d%d%d", &x, &a, &y, &b);
        ll k;
        scanf("%lld", &k);

        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
//        db2(x, a);
//        db2(y, b);

        int L = -1, R = n + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;

            vector<int> cnt(4);
            for (int i = 0; i < M; i++) {
                int t = i + 1;
                if (t % a == 0 && t % b == 0) {
                    cnt[3]++;
                } else if (t % a == 0) {
                    cnt[1]++;
                } else if (t % b == 0) {
                    cnt[2]++;
                }
            }
//            db(M);
//            dbv(cnt);
            ll cur = 0;
            for (int i = 0; i < n; i++) {
                if (cnt[3] > 0) {
                    cur += p[i] / 100 * (x  + y);
                    cnt[3]--;
                } else if (cnt[1] > 0) {
                    cur += p[i] / 100 * x;
                    cnt[1]--;
                } else if (cnt[2] > 0) {
                    cur += p[i] / 100 * y;
                    cnt[2]--;
                }
            }
//            db3(M, cur, k);
            if (cur >= k) R = M;
            else L = M;
        }
        if (R == n + 1) R = -1;
        printf("%d\n", R);
    }

    return 0;
}