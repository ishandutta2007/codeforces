#include <random>

#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const int MOD = 998244353;

const int N = 505;

int dp[N][N];
int sumdp[N][N];

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int stupid(int n, int m, vector<int> a) {
    memset(dp, 0, sizeof(dp));

    for (int len = 1; len <= m; len++) {
        for (int l = 0; l < m; l++) {
            int r = l + len - 1;
            if (r >= m) continue;

            int p = l;
            for (int i = l + 1; i <= r; i++) if (a[i] < a[p]) p = i;


            int sum1 = 0, sum2 = 0;
            for (int i = l; i <= p; i++) {
                int cur = 1;
                if (i > l) cur = mul(cur, dp[l][i - 1]);
                if (i < p) cur = mul(cur, dp[i][p - 1]);
                add(sum1, cur);
            }
            for (int j = p; j <= r; j++) {
                int cur = 1;
                if (j > p) cur = mul(cur, dp[p + 1][j]);
                if (j < r) cur = mul(cur, dp[j + 1][r]);
                add(sum2, cur);
            }
            int res = 1LL * sum1 * sum2 % MOD;

            dp[l][r] = res;
        }
    }
    return dp[0][m - 1];
}

void test() {
    int n = 500;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    shuffle(a.begin(), a.end(), std::mt19937(239));
    cout << stupid(n, n, a) << endl;
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(m);
        for (int i= 0; i < m; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        printf("%d\n", stupid(n, m, a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}