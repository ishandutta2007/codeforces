#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, anss, anse;
int A[300005][10];

int pos[300];
bool ok(int mn) {
    for (int i = 0; i < 300; ++i) pos[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int b = 0;
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] >= mn) b |= 1 << j - 1;
        }
        pos[b] = i;
    }
    for (int i = 0; i < 300; ++i) {
        if (!pos[i]) continue;
        for (int j = 0; j < 300; ++j) {
            if (!pos[j]) continue;
            if ((i | j) == (1 << m) - 1) {
                anss = pos[i];
                anse = pos[j];
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }
    int s = 0, e = 1e9;
    while (s < e) {
        int m = s + e + 1 >> 1;
        if (ok(m)) s = m;
        else e = m - 1;
    }
    ok(s);
    cout << anss << ' ' << anse;
}