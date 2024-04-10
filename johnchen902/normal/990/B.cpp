#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int  a[200000];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[i] == a[j])
            j++;
        if (j == n || a[j] > a[i] + k)
            ans++;
    }
    printf("%d\n", ans);
}