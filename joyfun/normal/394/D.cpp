#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int N = 1005;
int n, num[N];

void solve() {
    int ans = INF, start, dd;
    sort(num, num + n);
    for (int d = 0; d <= 20000; d++) {
        int up = -INF, down = INF;
        for (int i = 0; i < n; i++) {
            up = max(up, i * d - num[i]);
            down = min(down, i * d - num[i]);
        }
        int res = (up - down + 1) / 2;
        if (ans > res) {
            ans = res; start = -up + res; dd = d;
        }
    }
    printf("%d\n%d %d\n", ans, start, dd);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    solve();
    return 0;
}