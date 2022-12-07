#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

int n, m;
int a[N], pre[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1])
            pre[i] = pre[i - 1];
        else pre[i] = i - 1;
    }
    int l, r, x;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        if (x != a[r]) printf("%d\n", r);
        else if (pre[r] >= l && x != a[pre[r]]) printf("%d\n", pre[r]);
        else printf("-1\n");
    }
    return 0;
}