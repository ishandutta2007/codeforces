#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main() {
    ios::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = INT_MIN, r = INT_MAX;
    sort(a, a + n);
    for (int i = 0; i < n; i++) l = max(l, a[i] - i);
    int point = 0;
    for (int i = 0; i < n - p + 1; i++) {
        r = min(r, a[i + p - 1] - i);
    }
    if (r <= l) {
        cout << 0;
        return 0;
    }
    cout << r - l << endl;
    for (int i = l; i < r; i++) {
        cout << i << ' ';
    }
}