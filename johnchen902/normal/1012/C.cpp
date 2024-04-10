#include <cstdio>
#include <algorithm>
using namespace std;

constexpr int inf = 5000 * 100000;

int a[5003], dp[5001];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    // See https://codeforces.com/contest/1012/submission/40975171
    // for a more obvious version.
    int maxk = (n + 1) / 2;
    for (int k = 1; k <= maxk; k++) {
        int mem1 = inf;
        int mem2 = k == 1 ? 0 : inf;
        int mem3 = k == 1 ? 0 : inf;

        for (int i = 1; i <= n; i++) {
            int mem4 = dp[i];

            dp[i] = min(mem1, mem2 +
                    max(a[i - 1] - a[i] + 1, 0) +
                    max(min(a[i + 1], a[i + 2] - 1) - a[i] + 1, 0));

            mem1 = min(mem1, mem2 +
                    max(a[i - 1] - a[i] + 1, 0) +
                    max(a[i + 1] - a[i] + 1, 0));
            mem2 = mem3;
            mem3 = mem4;
        }

        printf("%d%c", mem1, k == maxk ? '\n' : ' ');
    }
}