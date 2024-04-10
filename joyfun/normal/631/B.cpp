#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5005;

int n, m, k;

pair<int, int> r[N], c[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) r[i] = make_pair(0, 0);
    for (int i = 1; i <= m; i++) c[i] = make_pair(0, 0);
    int tp, x, a;
    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &tp, &x, &a);
        if (tp == 1) r[x] = make_pair(a, i);
        else c[x] = make_pair(a, i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (r[i].second > c[j].second) printf("%d ", r[i].first);
            else printf("%d ", c[j].first);
        }
        printf("\n");
    }
    return 0;
}