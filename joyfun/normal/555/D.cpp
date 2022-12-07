#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, m, x[N], id[N], to[N];

bool cmp(int a, int b) {
    return x[a] < x[b];
}

int cal(int v, int len) {
    int tmp = upper_bound(x + 1, x + n + 1, x[v] + len) - x - 1;
    int len2 = len - (x[tmp] - x[v]);
    if (x[tmp] - len2 > x[tmp - 1]) return tmp;
    int lv = lower_bound(x + 1, x + n + 1, x[tmp] - len2) - x;
    if (lv == v) return cal(lv, len % (2 * (x[tmp] - x[v])));
    else return cal(lv, len - (x[tmp] - x[v] + x[tmp] - x[lv]));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    sort(x + 1, x + n + 1);
    x[0] = -2147483647;
    x[n + 1] = 2147483647;
    for (int i = 1; i <= n; i++)
        to[id[i]] = i;
    int a, len;
    while (m--) {
        scanf("%d%d", &a, &len);
        printf("%d\n", id[cal(to[a], len)]);
    }
    return 0;
}