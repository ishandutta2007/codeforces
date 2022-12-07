#include <stdio.h>
#include <string.h>

int n, m;
int parent[55];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    int ans = n;
    int x, y;
    for (int i = 1; i <= n; i++)
    parent[i] = i;
    while (m--) {
    scanf("%d%d", &x, &y);
    int pa = find(x);
    int pb = find(y);
    if (pa != pb) {
        parent[pa] = pb;
        n--;
    }
    }
    long long out = 1;
    for (int i = 0; i < ans - n; i++)
    out *= 2;
    printf("%lld\n", out);
    return 0;
}