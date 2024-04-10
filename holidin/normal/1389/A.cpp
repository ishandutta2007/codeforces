#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;

void solve() {
    int i, j, k, n, l, r;
    cin >> l >> r;
    if (2 * l <= r) {
        cout << l << ' ' << 2 * l << "\n";
    } else
        cout << -1 << ' ' << -1 << "\n";

}

int main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}