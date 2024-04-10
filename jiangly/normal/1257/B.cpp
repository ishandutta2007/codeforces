#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x, y;
    bool ans;
    cin >> x >> y;
    if (x >= 4) {
        ans = true;
    } else if (x >= 2) {
        ans = y <= 3;
    } else {
        ans = y == 1;
    }
    cout << (ans ? "YES" : "NO") << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}