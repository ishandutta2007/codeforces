#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, n, k, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        int v = 1;
        cin >> x;
        while (x >= v)
            v *= 2;
        if (x != v - 1)
            cout << v - 1 << "\n";
        else {
            int ans = 1;
            for (j = 2; j * j <= x; ++j)
            if (x % j == 0)
                ans = max(ans, x / j);
            cout << ans << "\n";
        }
    }
}