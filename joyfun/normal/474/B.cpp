#include <cstdio>
#include <cstring>

const int N = 1000005;
int n, a, vis[N];

int main() {
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j < a; j++) {
            s++;
            vis[s] = i;
        }
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        printf("%d\n", vis[a]);
    }
    return 0;
}