#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, p;
double x[N];

int main() {
    scanf("%d%d", &n, &p);
    int l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        int cnt = r / p - (l - 1) / p;
        x[i] = 1 - cnt * 1.0 / (r - l + 1);
    }
    x[n] = x[0];
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans + (1 - x[i] * x[i + 1]);
    ans *= 2000;
    printf("%.12f\n", ans);
    return 0;
}