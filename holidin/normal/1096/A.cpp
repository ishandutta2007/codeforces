#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
    int i, j, n, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        cout << l << ' ' << 2 * l << "\n";
    }
}