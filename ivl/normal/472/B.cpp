#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[2005];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    reverse(a, a + n);
    int r = 0;
    for (int i = 0; i < n; i += k) r += a[i] - 1;
    printf("%d\n", r * 2);
    return 0;
}