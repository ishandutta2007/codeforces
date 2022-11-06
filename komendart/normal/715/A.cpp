#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(int k, int a, int &na) {
    int tmp = k * (k + 1);
    int ans = tmp / k * tmp - a / k;
    cout << ans << ' ';
    na = tmp;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int a = 2;
    for (int i = 1; i <= n; i++) {
        solve(i, a, a);
    }
}