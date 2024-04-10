#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n / 2; ++i)
    for (j = 1; j <= k; ++j) {
        cout << i << ' ' << j << "\n";
        cout << n - i + 1 << ' ' << k - j + 1 << "\n";
    }
    if (n % 2 == 1)
        for (j = 1; j <= k; ++j) {
            cout << (n + 1) / 2 << ' ';
            if (j % 2 == 1)
                cout << (j + 1) / 2 << "\n";
            else
                cout << k - (j / 2) + 1 << "\n";
        }
}