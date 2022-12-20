#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

int a[N];

int main() {
    int i, j, n, k, h = 0, tek = 0, ans = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        h = max(h, a[i]);
    }
    for (i = 1; i <= n; ++i)
    if (a[i] == h) {
        ++tek;
        ans = max(ans, tek);
    } else
        tek  =0;
    cout << ans;
}