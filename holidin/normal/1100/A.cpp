#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int a[N];

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int ans = 0;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < k; ++i) {
        int sum = 0;
        for (j = 0; j < n; ++j)
        if (j % k != i)
            sum += a[j];
        ans = max(ans, abs(sum));
    }
    cout << ans;
}