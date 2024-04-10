#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    long long k;
    cin >> k;

    if (k < n) {
        cout << k + 1 << " " << 1 << '\n';
    } else {
        k -= n;
        m--;

        int row = n - k / m;
        int col = k % m;
        if (row % 2 == 0) {
            col += 2;
        } else {
            col = m + 1 - col;
        }

        cout << row << " " << col << '\n';
    }
}