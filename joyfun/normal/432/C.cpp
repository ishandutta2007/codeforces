#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 100005;

int pri[N], ans[5 * N][2], ansn = 0;

void init() {
    int vis[N];
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        pri[i] = 1;
        for (int j = i; j < N; j += i)
            vis[j] = 1;
    }
}

int n, num[N], v[N], i, snum[N];

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    init();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        snum[i] = num[i];
        v[num[i]] = i;
    }
    sort(snum, snum + n);
    i = 0;
    while (i < n) {
        while (v[snum[i]] != i) {
            for (int j = i; ;j++) {
                if (pri[v[snum[i]] - j + 1]) {
                    ans[ansn][0] = j + 1;
                    ans[ansn][1] = v[snum[i]] + 1;
                    ansn++;
                    int t = v[snum[i]];
                    v[snum[i]] = j;
                    v[num[j]] = t;
                    swap(num[j], num[t]);
                    break;
                }
            }
        }
        i++;
    }
    printf("%d\n", ansn);
    for (i = 0; i < ansn; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}