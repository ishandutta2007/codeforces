#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a = 0, ans = 0;
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        a -= x; ans = max(a, ans);
        a += y;
        ans = max(a, ans);
    }
    cout << ans << '\n';
}