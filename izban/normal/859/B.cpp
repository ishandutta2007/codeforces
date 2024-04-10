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
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            int j = (n + i - 1) / i;
            if (1LL * i * j >= n) ans = min(ans, 2 * (i + j));
        }
        printf("%d\n", ans);
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}