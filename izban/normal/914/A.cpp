#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (x < 0) ans = max(ans, x);
            int y = sqrt(x);
            while (y * y < x) y++;
            while (y * y > x) y--;
            if (y * y != x) ans = max(ans, x);
        }
        cout << ans << endl;
    }

    return 0;
}