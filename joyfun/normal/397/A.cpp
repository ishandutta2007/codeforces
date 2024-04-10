#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 105;
int n, i, vis[N], l, r, ll, rr;

int main() {
    scanf("%d", &n);
    scanf("%d%d", &ll, &rr);
    for (i = 2; i <= n; i++) {
        scanf("%d%d", &l, &r);
        for (int j = l; j < r; j++)
            vis[j] = 1;
    }
    int ans = 0;
    for (i = ll; i < rr; i++) {
        if (!vis[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}