#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int c1, c2;
int ans = 0;

int get(int x) {
    int cnt = 0;
    x--;
    while (x) {
        cnt++;
        x /= 7;
    }
    if (cnt == 0) cnt++;
    return cnt;
}

int ss[10];

void gao() {
    int a1 = 0, a2 = 0;
    for (int i = 0; i < c1; i++) {
        a1 = a1 * 7 + ss[i];
    }
    for (int i = c1; i < c1 + c2; i++)
        a2 = a2 * 7 + ss[i];
    if (a1 < n && a2 < m) {
       // printf("%d %d\n", a1, a2);
        ans++;
       // for (int i = c1; i < c2; i++) printf("%d ", ss[i]); printf("\n");
    }
}

void dfs(int u, int s) {
    if (u == c1 + c2) {
        gao();
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (s&(1<<i)) continue;
        ss[u] = i;
        dfs(u + 1, s^(1<<i));
    }
}

int main() {
    scanf("%d%d", &n, &m);
    c1 = get(n);
    c2 = get(m);
    if (c1 + c2 > 7) printf("0\n");
    else {
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}