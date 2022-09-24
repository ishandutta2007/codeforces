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


int MOD;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int slow(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(2 * n));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(dp[i][i], 1);
        for (int j = 0; j < 2 * n; j++) {
            if (dp[i][j] == 0) continue;
            add(ans, dp[i][j]);
            for (int k = i + 1; k <= n; k++) {
                if ((j ^ k) > j) {
                    add(dp[k][j ^ k], dp[i][j]);
                }
            }
        }
    }
    return ans;
}

int solve(int n) {
//    vector<int> a;
//    for (int x = n; x; x >>= 1) {
//        a.push_back(x % 2);
//    }
//    reverse(a.begin(), a.end());
//
//    int k = a.size();
//    int ans = 0;
//
//    int cur = 1;
//    int prod = 1;
//    for (int i = 1; i <= k - 1; i++) {
//        prod = mul(prod, cur + 1);
//        cur = mul(cur, 2);
//    }
//
//    ans = prod;
//
//    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(k + 1, vector<int>(2)));

    vector<int> sizes;
    int x = 1;
    while (x * 2 <= n) {
        sizes.push_back(x);
        x *= 2;
    }
    sizes.push_back(n - x + 1);

    int ans = 1;
    for (int y : sizes) {
        ans = mul(ans, y + 1);
    }
    ans = (ans - 1 + MOD) % MOD;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    if (0) {
        MOD = 1e9 + 7;
        for (int i = 1; i <= 1e3; i++) {
            db(i);
            int a1 = solve(i);
            int a2 = slow(i);
            assert(a1 == a2);
        }
        return 0;
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d%d", &n, &MOD);
        printf("%d\n", solve(n));
    }

    return 0;
}