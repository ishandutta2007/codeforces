#include <cstdio>
#include <algorithm>
using namespace std;
int r[100000];
int main() {
    int n, k, m = 0;
    scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++)
        if(getchar() == '0')
            r[m++] = i;
    int ans = n;
    for(int i = 0, j = k + 1, l = 0; j <= m; i++, j++) {
        while(l + 1 < j && max(r[j - 1] - r[l + 1], r[l + 1] - r[i]) < max(r[j - 1] - r[l], r[l] - r[i]))
            l++;
        ans = min(ans, max(r[j - 1] - r[l], r[l] - r[i]));
    }
    printf("%d\n", ans);
}