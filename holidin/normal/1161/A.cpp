#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 1e6 + 1;
const int inf = 1e9;
int mn[N], mx[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        mn[i] = inf;
        mx[i] = 0;
    }
    for (i = 1; i <= k; ++i) {
        cin >> j;
        mn[j] = min(i, mn[j]);
        mx[j] = max(i, mx[j]);
    }
    int ans = 0;
    for (i = 1; i <= n; ++i) {
        if (mn[i] == inf)
            ++ans;
        if (i > 1 && mn[i] > mx[i - 1])
            ++ans;
        if (i < n && mn[i] > mx[i + 1])
            ++ans;
    }
    cout << ans;
}