#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve(int si, int fi) {
    if (si > fi) {
        return;
    }
    cout << si << " " << 1 << "\n";
    if (si == fi) {
        int a, b;
        a = 2;
        b = m;
        for (int i = 1; i < m; ++i) {
            if (i % 2 == 1) {
                cout << si << " " << b << "\n";
                b--;
            } else {
                cout << si << " " << a << "\n";
                a++;
            }
        }
        return;
    }
    for (int i = 1; i < m; ++i) {
        cout << fi << " " << m - i + 1 << "\n";
        cout << si << " " << i + 1 << "\n";
    }
    cout << fi << " " << 1 << "\n";
    solve(si + 1, fi - 1);
}

main() {
    cin >> n >> m;
    solve(1, n);
    return 0;
}