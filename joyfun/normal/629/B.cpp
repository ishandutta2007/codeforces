#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5005;

int n;
int a[N], b[N];
char c[N][2];

int cal(int x) {
    int f = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (x >= a[i] && x <= b[i]) {
            if (c[i][0] == 'M') m++;
            else f++;
        }
    }
    return min(f, m);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s%d%d", c[i], &a[i], &b[i]);
    int ans = 0;
    for (int i = 1; i <= 366; i++)
        ans = max(ans, cal(i));
    printf("%d\n", ans * 2);
    return 0;
}