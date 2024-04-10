#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a1, b1, c1, a2, b2, c2;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        int ans = 2 * min(c1, b2);
        int k = min(c1, b2);
        c1 -= k;
        b2 -= k;
        int num = a1 + c1;
        num = max(0, c2 - num);
        ans -= 2 * num;
        cout << ans << endl;
    }
}