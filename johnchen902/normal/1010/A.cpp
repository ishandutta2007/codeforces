#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000], b[1000];

double solve(int n, int m) {
    double ans = m;

    ans = ans * b[0] / (b[0] - 1);
    for (int i = n - 1; i > 0; i--) {
        ans = ans * a[i] / (a[i] - 1);
        ans = ans * b[i] / (b[i] - 1);
    }
    ans = ans * a[0] / (a[0] - 1);

    return ans - m;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);

    if (count(a, a + n, 1) || count(b, b + n, 1))
        puts("-1");
    else
        printf("%.9f\n", solve(n, m));
}