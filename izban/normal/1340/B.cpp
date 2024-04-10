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

const int T = 10;
const int D = 7;
const string s[T] = {
        "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};
int sMask[T];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i <T; i++) {
        for (int j= 0; j < D; j++) {
            sMask[i] |= ((int)(s[i][j] - '0')) << j;
        }
    }

    int n, k;
    while (cin >> n >> k) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> aMask(n);
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < D; j++) {
                aMask[i] |= ((int) (a[i][j] - '0')) << j;
            }
        }

        vector<vector<int>> cost(n, vector<int>(T));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < T; j++) {
                bool ok = 1;
                int cnt = 0;

                ok = (aMask[i] | sMask[j]) == sMask[j];
                cnt = __builtin_popcount(aMask[i] ^ sMask[j]);
                if (!ok) cnt = 1e9;
                cost[i][j] = cnt;
            }
        }

        vector<vector<char>> can(n + 1, vector<char>(k + 1));
        can[n][0] = 1;
        for (int i = n; i > 0; i--) {
            for (int j = 0; j <= k; j++) {
                if (!can[i][j]) continue;
                for (int c = 0; c < 10; c++) {
                    if (j + cost[i - 1][c] <= k) {
                        can[i - 1][j + cost[i - 1][c]] = 1;
                    }
                }
            }
        }

        if (!can[0][k]) {
            cout << -1 << endl;
        } else {
            string ans = "";
            for (int i = 0; i < n; i++) {
                for (int c = 9; c >= 0; c--) {
                    if (k - cost[i][c] >= 0 && can[i + 1][k - cost[i][c]]) {
                        ans += (char)('0' + c);
                        k -= cost[i][c];
                        break;
                    }
                }
            }
            assert((int)ans.length() == n);
            cout << ans << endl;
        }
    }

    return 0;
}