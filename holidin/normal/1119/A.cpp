#include <bits/stdc++.h>
using namespace std;
const int N  = 5e5 + 1;
int c[N];
int main() {
    int i, j, k, n, m, a, b, s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    int ans = 0;
    for (i = 1; i <= n; ++i) {
        if (c[i] != c[n])
            ans = max(ans, n - i);
        if (c[1] != c[i])
            ans = max(ans, i - 1);
    }
    cout << ans;
}