#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
        l[i] = i > 0 && a[i] > a[i - 1] ? l[i - 1] + 1 : 1;
    for (int i = n - 1; i >= 0; --i)
        r[i] = i < n - 1 && a[i] < a[i + 1] ? r[i + 1] + 1 : 1;
    int ans = *max_element(l.begin(), l.end());
    for (int i = 1; i < n - 1; ++i)
        if (a[i - 1] < a[i + 1])
            ans = max(ans, l[i - 1] + r[i + 1]);
    cout << ans << endl;
    return 0;
}