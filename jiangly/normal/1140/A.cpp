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
    int ans = 0;
    for (int i = 0, j = 0, k = 0; i < n; ) {
        while (j == i || j < k) {
            k = max(a[j], k);
            ++j;
        }
        i = j;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}