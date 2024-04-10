#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = (int)1e9 + 1;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end());

        int L = -1, R = INF + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;

            /*bool ok = 1;
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j + 1 < n && a[j + 1] - a[i] <= M) j++;
                ok &= j - i + 1 >= k;
                i = j;
            }*/
            vector<int> vct;
            vector<char> dp(n + 1);
            dp[0] = 1;
            vct.push_back(0);
            int j = 0;
            for (int i = 1; i <= n; i++) {
                while (j < (int)vct.size() && a[i - 1] - a[vct[j]] > M) j++;
                if (j < (int)vct.size() && i - vct[j] >= k) dp[i] = 1;
                if (dp[i]) vct.push_back(i);
            }
            bool ok = dp[n];
            if (ok) R = M;
            else L = M;
        }
        printf("%d\n", R);
    }
    
    return 0;
}