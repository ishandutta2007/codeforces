#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int INF = (1<<31) - 1;
const int N = 100005;
int n, m;
int a[N], b[N];

int main() {
    int an = 0;
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int r = 0;
    for (int i = 0; i < n; i++) {
        int rr = lower_bound(b, b + m, a[i]) - b;
        int tmp = INF;
        if (rr < m) tmp = min(tmp, b[rr] - a[i]);
        rr--;
        if (rr >= 0) tmp = min(tmp, a[i] - b[rr]);
        r = max(r, tmp);
    }
    printf("%d\n", r);
    return 0;
}