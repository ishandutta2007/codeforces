#include <cstdio>
#include <bitset>
#include <iostream>
#include <algorithm>
#define maxn 23
using namespace std;
int read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) {
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return x;
}
int n, m, cnt, ans = 1000, ans2;
bitset<maxn> vis[maxn];
void dfs(int state, int sum, int dep) {
    if (sum >= ans) {
        return;
    }
    if (dep == n) {
        if (cnt == 0) {
            ans = sum;
            ans2 = state;
        }
        return;
    }
    dfs(state, sum, dep + 1);
    bitset<maxn> tmp[maxn];
    for (int i = 0; i < n; ++i) {
        if (vis[dep][i]) {
            tmp[i] = vis[i];
            vis[i] |= vis[dep];
            cnt -= (vis[i] ^ tmp[i]).count();
        }
    }
    dfs(state | 1 << dep, sum + 1, dep + 1);
    for (int i = 0; i < n; ++i) {
        if (vis[dep][i]) {
            cnt += (vis[i] ^ tmp[i]).count();
            vis[i] = tmp[i];
        }
    }
}
int main() {
    n = read(), m = read();
    cnt = n * n;
    for (int i = 1; i <= m; ++i) {
        int x = read() - 1, y = read() - 1;
        vis[x][y] = 1, vis[y][x] = 1;
        cnt -= 2;
    }
    for (int i = 0; i < n; ++i) {
        vis[i][i] = 1;
        cnt--;
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
    for (int i = 0; 1 << i <= ans2; i++) {
        if ((1 << i) & ans2) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}