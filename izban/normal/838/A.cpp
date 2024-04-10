#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1e9;

const int N = 5200;

char buf[N];
int s[N][N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            a[i] = buf;
        }

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
                if (i <= n && j <= m) s[i][j] += a[i - 1][j - 1] - '0';
            }
        }

        auto getSum = [&](int i, int j, int k) {
            int ii = i + k;
            int jj = j + k;

            int ans = 0;
            ans += s[ii][jj];
            ans -= s[i][jj];
            ans -= s[ii][j];
            ans += s[i][j];
            return ans;
        };

        int ans = INF;
        for (int k = 2; k <= max(n, m); k++) {
            int cans = 0;
            for (int i = 0; (i + 1) * k < N; i++) {
                for (int j = 0; (j + 1) * k < N; j++) {
                    int csum = getSum(i * k, j * k, k);
                    cans += min(csum, k * k - csum);
                }
            }
            ans = min(ans, cans);
        }
        printf("%d\n", ans);
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}