#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

int n, k, a[N];

int main() {
    scanf("%d%d", &n, &k);
    int m;
    int tot = 0;
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
            scanf("%d", &a[j]);
        int j = 1;
        if (a[0] == 1) {
            int cnt = 2;
            for (; j < m; j++) {
                if (a[j] != cnt)
                    break;
                cnt++;
            }
            tmp = cnt - 1;
        }
        ans += m - j;
    }
    printf("%d\n", ans + n - tmp);
    return 0;
}