#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, m, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt = min(a[i], cnt + 1);
    printf("%d\n", cnt + 1);
    return 0;
}