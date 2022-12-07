#include <cstdio>
#include <cstring>

const int N = 55;

int p, q, l, r, ans;
int vis[10005], c[N], d[N];

bool judge(int t) {
    for (int i = 0; i < q; i++) {
        for (int j = c[i]; j <= d[i]; j++) {
            if (vis[j + t])
                return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d%d", &p, &q, &l, &r);
    int a, b;
    for (int i = 0; i < p; i++) {
        scanf("%d%d", &a, &b);
        for (int j = a; j <= b; j++)
            vis[j] = 1;
    }
    for (int i = 0; i < q; i++)
        scanf("%d%d", &c[i], &d[i]);
    for (int i = l; i <= r; i++) {
        if (judge(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}