#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

const int MX = 2e5 + 9;
int pre[MX], chk[MX];

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        memset(pre, 0, sizeof(pre));
        memset(chk, 0 ,sizeof(chk));
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            chk[x]++;
        }
        if (m == n) {
            puts("YES");
            continue;
        }
        if ((n - m) % (k - 1) != 0) {
            puts("NO");
            continue;
        }
        bool yes = false;
        for (int i = 2; i <= n; i++) {
            if (!chk[i - 1])
                pre[i]++;
            pre[i] += pre[i - 1];
            if (chk[i] && pre[i] >= ((k - 1) / 2) && (n - m - pre[i]) >= (k - 1) / 2)
                yes = true;
        }
        if (yes) puts("YES");
        else puts("NO");
    }
    return 0;
}