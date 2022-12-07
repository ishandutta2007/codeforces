#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, k;
char str[N];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str + 1);
    int r1 = 1, r2 = 1;
    int c1 = 0, c2 = 0;
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        while (r1 <= n && c1 + (str[r1] == 'b') <= k) {
            c1 += (str[r1++] == 'b');
        }
        while (r2 <= n && c2 + (str[r2] == 'a') <= k) {
            c2 += (str[r2++] == 'a');
        }
        ans = max(ans, r1 - l);
        ans = max(ans, r2 - l);
        c1 -= (str[l] == 'b');
        c2 -= (str[l] == 'a');
    }
    printf("%d\n", ans);
    return 0;
}