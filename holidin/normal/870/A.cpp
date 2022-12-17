#include <bits/stdc++.h>
using namespace std;

bool b1[10], b2[10];

int main() {
    int n, m, i, j1, j2;
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        cin >> j1;
        b1[j1] = true;
    }
    for (i = 1; i <= m; ++i) {
        cin >> j2;
        b2[j2] = true;
    }
    for (i = 1; i <= 9; ++i)
    if (b1[i] && b2[i]) {
         cout << i << endl;
         return 0;
    }
    j1 = 1; j2 = 1;
    while (!b1[j1]) ++j1;
    while (!b2[j2]) ++j2;
    cout << min(j1, j2) << max(j1, j2);
}