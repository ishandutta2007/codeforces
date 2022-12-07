#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, vis[N];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (vis[i]) continue;
        cnt++;
        if (1ll * i * i > 1ll * n + 1) continue;
        for (int j = i * i; j <= n + 1; j += i)
            vis[j] = 1;
    }
    printf("%d\n", cnt == n ? 1 : 2);
    for (int i = 2; i <= n + 1; i++) {
        printf("%d ", vis[i] + 1);
    } printf("\n");
    return 0;
}