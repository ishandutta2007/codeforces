#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int f[1111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        f[x] = 1;
    }

    int ans = 1;
    for (int i = 0; i <= 1000000; ++i)
        if (f[i] > 0) {
            for (int j = i + i; j <= 1000000; j += i)
                if (f[j] > 0)
                    f[j] = max(f[j], f[i] + 1);
            if (f[i] > ans) ans = f[i];
        }
    cout << ans << endl;
    
    return 0;
}