#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;
int f[1000000], g[1000000], fg[2000000];
bool ok(int n, int m, int k, int x) {
    merge(f, f + n, g + x, g + m, fg);
    for(int i = 0; i < n + m - x; i++)
        if(fg[i] < i / k)
            return false;
    return true;
}
int solve(int n, int m, int k) {
    int l = 0, r = m + 1;
    while(l < r) {
        int x = (l + r) / 2;
        if(ok(n, m, k, x))
            r = x;
        else
            l = x + 1;
    }
    return m - r;
}
int id[1000000];
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", f + i);
    for(int i = 0; i < m; i++)
        scanf("%d", g + i);
    sort(f, f + n);
    iota(id, id + m, 0);
    sort(id, id + m, [](int l, int r) {
        return g[l] > g[r];
    });
    sort(g, g + m);
    int ans = solve(n, m, k);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        printf("%d%c", id[i] + 1, i == ans - 1 ? '\n' : ' ');
}