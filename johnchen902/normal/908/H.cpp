#include <algorithm>
#include <cstdio>
#include <ctime>
#include <numeric>
using namespace std;

char a[47][48];
bool vis[47];
int pa[47], cnt[47], pb[47];
bool b[23][23];
int perm[23];
int color[23];
bool colorused[23];

void dfs(int i, int p, int n) {
    vis[i] = true;
    pa[i] = p;
    cnt[p]++;
    for (int j = 0; j < n; j++)
        if (a[i][j] == 'A' && not vis[j])
            dfs(j, p, n);
}

int solve2(int m) {
    clock_t start = clock();
    int ans = m;
    iota(perm, perm + m, 0);
    while (ans > 1 && (clock() - start) < 4.5 * CLOCKS_PER_SEC) {
        random_shuffle(perm, perm + m);
        int cur = 0;
        for (int i = 0; i < m; i++) {
            fill_n(colorused, m, false);
            for (int j = 0; j < i; j++)
                if (b[perm[i]][perm[j]])
                    colorused[color[j]] = true;
            color[i] = find(colorused, colorused + m, false) - colorused;
            cur = max(cur, color[i] + 1);
            if (cur >= ans)
                break;
        }
        ans = min(cur, ans);
    }
    return ans;
}

int solve(int n) {
    for (int i = 0; i < n; i++)
        if (not vis[i])
            dfs(i, i, n);
    int m = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i] >= 2)
            pb[i] = m++;
    // possible
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != 'X')
                continue;
            if (pa[i] == pa[j])
                return -1;
            if (cnt[pa[i]] == 1 || cnt[pa[j]] == 1)
                continue;
            b[pb[pa[i]]][pb[pa[j]]] = true;
            b[pb[pa[j]]][pb[pa[i]]] = true;
        }
    return n + solve2(m) - 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    printf("%d\n", solve(n));
}