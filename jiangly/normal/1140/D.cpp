#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n - 1; ++i)
        ans += i * (i + 1);
    cout << ans << endl;
    return 0;
}