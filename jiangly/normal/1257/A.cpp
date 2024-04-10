#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    cout << min(n - 1, abs(a - b) + x) << "\n";
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