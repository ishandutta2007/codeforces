#include <bits/stdc++.h>
using namespace std;
int a[10000];
int div(int l, int r, int h) {
    if (l > r) return 0;
    int mmin = 0x3f3f3f3f, p = 0, ans = 0;
    for (int i = l; i <= r; i++)
        if (a[i] < mmin) mmin = a[i], p = i;

    return min(mmin - h + div(l, p - 1, mmin) + div(p + 1, r, mmin), r - l + 1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << div(1, n, 0);
}