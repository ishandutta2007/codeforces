#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

int main() {
    int x1, y1, x2, y2, i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << "YES\n";
    for (i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e9;
        y1 += 1e9;
        cout << 2 * (x1 % 2) + y1 % 2 + 1 << "\n";
    }
}