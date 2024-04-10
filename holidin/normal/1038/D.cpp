#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

long long a[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0, mn = 1e9;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        ans += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    bool flag = false;
    for (i = 1; i < n; ++i)
    if (a[i] * a[i - 1] <= 0)
        flag = true;
    if (flag)
        cout << ans;
    else
        cout << ans - 2 * mn;
}