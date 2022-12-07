#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1000005;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n, m, i, j;
int a[3005], b[3005];
int Max = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    int l = 0, r = 0;
    while (l < n && r < m) {
        if (a[l] <= b[r]) {
            l++; r++;
        }
        else {
            r++;
        }
    }
    ans = n - l;
    printf("%d\n", ans);
    return 0;
}