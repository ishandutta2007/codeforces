#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100'000;
int n, q;
int a[2][N];
int cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (a[x][y] == 1) {
            for (int i = y - 1; i <= y + 1; ++i)
                if (i >= 0 && i < n && a[x ^ 1][i] == 1)
                    --cnt;
        } else {
            for (int i = y - 1; i <= y + 1; ++i)
                if (i >= 0 && i < n && a[x ^ 1][i] == 1)
                    ++cnt;
        }
        a[x][y] ^= 1;
        if (cnt == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}