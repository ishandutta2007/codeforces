#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, k, a, m, x[N];
int tmp[N];

bool judge(int mid) {
    for (int i = 1; i <= mid; i++) tmp[i] = x[i];
    sort(tmp + 1, tmp + 1 + mid);
    tmp[0] = 0;
    tmp[mid + 1] = n + 1;
    int tot = 0;
    for (int i = 0; i <= mid; i++)
        tot += (tmp[i + 1] - tmp[i]) / (a + 1);
    return tot >= k;
}

int main() {
    scanf("%d%d%d", &n, &k, &a);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &x[i]);
    if (judge(m)) printf("-1\n");
    else {
        int l = 1, r = m;
        while (l < r) {
            int mid = (l + r)>>1;
            if (judge(mid)) l = mid + 1;
            else r = mid;
        }
        if (judge(l)) l = -1;
        printf("%d\n", l);
    }
    return 0;
}