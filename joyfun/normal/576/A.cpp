#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int n;
int prime[N], vis[N], pn;
int ans[N], an;

int main() {
    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        prime[pn++] = i;
        for (int j = i * i; j < N; j += i) {
            vis[j] = 1;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < pn && prime[i] <= n; i++) {
        int tmp = prime[i];
        while (tmp <= n) {
            ans[an++] = tmp;
            tmp *= prime[i];
        }
    }
    printf("%d\n", an);
    for (int i = 0; i < an; i++) printf("%d ", ans[i]);
    return 0;
}