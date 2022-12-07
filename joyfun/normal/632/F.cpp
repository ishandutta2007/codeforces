#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;

const int N = 2505;

int n, g[N][N], an;
bitset<2501> s[N];

struct Node {
    int val, x, y;
    void read(int x, int y) {
        this->x = x;
        this->y = y;
        scanf("%d", &val);
        g[x][y] = val;
    }
    bool operator < (const Node &c) const {
        return val < c.val;
    }
} a[N * N];

int tmp[N * N], tn;

bool check() {
    for (int i = 0; i < tn; i++) {
        int u = a[tmp[i]].x;
        int v = a[tmp[i]].y;
        if ((s[u]|s[v]).count() != n) return false;
    }
    for (int i = 0; i < tn; i++) {
        int u = a[tmp[i]].x;
        int v = a[tmp[i]].y;
        s[u][v] = 0;
    }
    return true;
}

bool judge() {
    for (int i = 1; i <= n; i++) {
        if (g[i][i]) return false;
        for (int j = i + 1; j <= n; j++) {
            if (g[i][j] != g[j][i]) return false;
        }

    }
    tmp[tn++] = 0;
    for (int i = 1; i < an; i++) {
        if (a[i].val != a[i - 1].val) {
            if (!check()) return false;
            tn = 0;
            tmp[tn++] = i;
        } else tmp[tn++] = i;
    }
    return check();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[an++].read(i, j);
            s[i][j] = true;
        }
    }
    sort(a, a + an);
    printf("%s\n", judge() ? "MAGIC" : "NOT MAGIC");
    return 0;
}