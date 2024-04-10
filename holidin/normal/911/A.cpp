#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int mn = 2e9, pos = -1, ans = 1e9;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        if (j == mn) {
            ans = min(ans, i - pos);
            pos = i;
        }
        if (j < mn) {
            pos = i;
            ans = 1e9;
            mn = j;
        }
    }
    cout << ans;
}