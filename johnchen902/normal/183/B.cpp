#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

long long get_x(int x1, int y1, int x2, int y2, int y) {
    // returns -1 for non-integers
    if (y2 == y1)
        return -1;
    long long prod = (long long) (x2 - x1) * (y - y1);
    if (prod % (y2 - y1))
        return -1;
    return prod / (y2 - y1) + x1;
}

int ans[1000000];
int x[250], y[250];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", x + i, y + i);

    fill_n(ans, n, 1);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            long long x0 = get_x(x[i], y[i], x[j], y[j], 0);
            if (x0 < 1 || x0 > n)
                continue;

            int cnt = 0;
            for (int k = 0; k < m; k++)
                if (get_x(x[i], y[i], x[j], y[j], y[k]) == x[k])
                    cnt++;

            ans[x0 - 1] = max(ans[x0 - 1], cnt);
        }
    }
    
    printf("%d\n", accumulate(ans, ans + n, 0));
}