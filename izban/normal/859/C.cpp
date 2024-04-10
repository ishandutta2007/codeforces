#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> s(n + 1);
        s[n - 1] = 0;
        for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + a[i];

        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(a[i] + (s[i + 1] - dp[i + 1]), dp[i + 1]);
        }
        printf("%d %d\n", s[0] - dp[0], dp[0]);
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}