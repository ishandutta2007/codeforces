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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            static char buf[111111];
            scanf("%s", buf);
            a[i] = buf;
        }

        int cnt = 0;
        for (int i =0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += a[i][j] == 'R';
            }
        }

        string alph;
        for (char c = 'a'; c <= 'z'; c++) alph += c;
        for (char c = 'A'; c <= 'Z'; c++) alph += c;
        for (char c = '0'; c <= '9'; c++) alph += c;

        vector<string> ans(n, string(m, '#'));
        int curColor = 0;
        int curRice = 0;
        for (int i = 0; i < n; i++) {
            int ni, fi, di;
            if (i % 2 == 0) {
                ni = 0;
                fi = m-1;
                di = 1;
            } else {
                ni = m-1;
                fi = 0;
                di = -1;
            }
            for (int j = ni;; j += di) {
                ans[i][j] = alph[curColor];
                curRice += a[i][j] == 'R';

                int needRice = cnt / k;
                needRice += curColor < cnt % k;
                if (curRice == needRice && curColor < k - 1) {
                    curColor++;
                    curRice = 0;
                }

                if (j == fi) break;
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << endl;
    }

    return 0;
}