#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define pre(i, a, b) for (int i = a; i >= b; i--)
#define N 250005
using namespace std;
vector<int> a[N];
int n, m, v[N], c[N], t, s[N], f[N];
bool check(int x, int y) {
    int u = a[1][x], v = a[1][y];
    rep(i, 2, n) f[i] = s[i];
    rep(i, 2, n) if (f[i] >= 3) {
        u = a[i][x];
        break;
    }
    rep(i, 2, n) if (a[i][x] == a[1][x] && a[i][x] != u) f[i]++;
    else if (a[i][x] != a[1][x] && a[i][x] == u) f[i]--;
    rep(i, 2, n) if (f[i] > 3) { return false; }
    rep(i, 2, n) if (f[i] == 3) {
        v = a[i][y];
        break;
    }
    rep(i, 2, n) if (a[i][y] == a[1][y] && a[i][y] != v) f[i]++;
    else if (a[i][y] != a[1][y] && a[i][y] == v) f[i]--;
    rep(i, 2, n) if (f[i] > 2) return false;
    puts("Yes");
    rep(i, 1, m) printf("%d ", i == x ? u : (i == y ? v : a[1][i]));
    putchar('\n');
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) a[i].push_back(0);
    rep(i, 1, n) rep(j, 1, m) {
        int x;
        scanf("%d", &x);
        a[i].push_back(x);
    }
    bool flag = true;
    rep(i, 2, n) {
        rep(j, 1, m) s[i] += a[i][j] != a[1][j];
        if (s[i] > 4) {
            puts("No");
            return 0;
        }
        rep(j, 1, m) v[j] |= a[i][j] != a[1][j];
        flag &= s[i] < 3;
    }
    rep(i, 2, n) if (flag) {
        puts("Yes");
        rep(j, 1, m) printf("%d ", a[1][j]);
        putchar('\n');
        return 0;
    }
    rep(j, 1, m) if (v[j]) c[++t] = j;
    rep(i, 1, t) rep(j, 1, t) if (i != j) if (check(c[i], c[j])) return 0;
    puts("No");
    return 0;
}