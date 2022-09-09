#include<bits/stdc++.h>
using namespace std;
int a[401][401],s[401][401];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        memset(s, 0, sizeof(s));
        scanf("%d%d", &n, &m);
        for (int i = 1;i <= n;i++) {
            s[i][0] = 0;
            for (int j = 1;j <= m;j++) {
                scanf("%1d", &a[i][j]);
                s[i][j] = s[i][j - 1] + a[i][j];
            }

        }
        int ans = 1e9;
        for (int i = 1;i <= m;i++) {
            for (int j = i + 3;j <= m;j++) {
                int mx = 0, P0 = j - i - 1 - (s[1][j - 1] - s[1][i]), lt = 0;
                int P = P0;
                for (int k = 2;k < 5;k++)P += (s[k][j - 1] - s[k][i])+(!a[k][i])+(!a[k][j]);
                for (int k = 5;k <= n;k++) {
                    if (k > 5) {
                        lt += (s[k - 4][j - 1] - s[k - 4][i]) + (!a[k - 4][j]) + (!a[k - 4][i]);
                        mx = max(mx, lt+P0-(j-1-i-(s[k-4][j-1]-s[k-4][i])));
                    }
                    // cout <<i<<j<< P << lt << P0<<endl;
                    ans = min(ans,P+ (j-1-i-(s[k][j - 1] - s[k][i])) - mx);
                    P += (s[k][j - 1] - s[k][i]) + (!a[k][i]) + (!a[k][j]);
                }
            }
        }
        printf("%d\n", ans);
    }
}