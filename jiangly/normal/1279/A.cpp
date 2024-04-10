#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << (a[2] <= a[0] + a[1] + 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}