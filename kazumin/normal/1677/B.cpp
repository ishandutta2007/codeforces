#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2000005;

int t, n, m, a[MN], psa[MN], ans[MN], col[MN];
char c;

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= n * m; i++) a[i] = psa[i] = ans[i] = 0;
        for (int i = n * m + 1; i <= 2 * n * m; i++) {
            cin >> c;
            a[i] = c - '0';
            psa[i] = psa[i - 1] + a[i];
            ans[i] = 0;
        }
        for (int st = 1; st <= m; st++) {
            int cnt = 0, l, r;
            for (int i = 0; i < n; i++) {
                l = st + i * m, r = l + m - 1;
                if (psa[r] - psa[l - 1]) cnt++;
            }
            ans[r] += cnt;
            for (int i = n; i < 2 * n; i++) {
                l = st + i * m, r = l + m - 1;
                int lo = l - n * m, ro = r - n * m;
                if (psa[r] - psa[l - 1]) cnt++;
                if (psa[ro] - psa[lo - 1]) cnt--;
                ans[r] += cnt;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n * m; i++) {
            int num = i % m;
            col[num] = 0;
        }
        for (int i = n * m + 1; i <= 2 * n * m; i++) {
            int num = i % m;
            if (a[i]) {
                if (!col[num]) cnt++;
                col[num]++;
            }
            if (a[i - n * m]) {
                col[num]--;
                if (!col[num]) cnt--;
            }
            ans[i] += cnt;
        }
        for (int i = n * m + 1; i <= 2 * n * m; i++) printf("%lld ", ans[i]);
        printf("\n");
    }

    return 0;
}