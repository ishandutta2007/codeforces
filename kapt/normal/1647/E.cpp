#include <bits/stdc++.h>
using namespace std;

const int MAXLN = 30, MAXN = 1e5;
int jump[MAXLN][MAXN];
int a[MAXN], used[MAXN];
int b[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> jump[0][i];
        jump[0][i]--;
        used[jump[0][i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt++;
        }
    }
    int mx = 0;
    set<int> lft;
    for (int i = 0; i < n; ++i) {
        lft.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        a[i]--;
        lft.erase(a[i]);
    }
    mx -= n;
    int k = mx / cnt;
    fill(used, used + n, 0);
    for (int i = 1; i < MAXLN; ++i) {
        for (int v = 0; v < n; ++v) {
            jump[i][v] = jump[i - 1][jump[i - 1][v]];
        }
    }
    for (int v = 0; v < n; ++v) {
        int u = v;
        int k1 = k;
        for (int i = MAXLN - 1; i >= 0; --i) {
            if ((1 << i) <= k1) {
                u = jump[i][u];
                k1 -= (1 << i);
            }
        }
        if (used[u]) {
            b[v] = *lft.lower_bound(a[u]);
            lft.erase(b[v]);
        } else {
            b[v] = a[u];
        }
        used[u] = true;
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] + 1 << " ";
    }
    return 0;
}