#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100000], p[100000];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> p[i];
    for (int i = 1; i < n; ++i) p[i] = min(p[i], p[i - 1]);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += p[i] * a[i];
    cout << ans << endl;
}