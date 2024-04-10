#include <cstdio>
#include <algorithm>
using namespace std;
bool a[300000];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    int maxl = 0, maxr = 0;
    for(int l = 0, r = 0, c0 = 0;;) {
        if(r - l > maxr - maxl)
            maxr = r, maxl = l;

        if(r == n)
            break;
        c0 += a[r++] == 0;
        while(c0 > k)
            if(a[l++] == 0)
                c0--;
    }
    printf("%d\n", maxr - maxl);
    for(int i = 0; i < maxl; i++)
        printf("%d ", (int) a[i]);
    for(int i = maxl; i < maxr; i++)
        printf("%d ", 1);
    for(int i = maxr; i < n; i++)
        printf("%d ", (int) a[i]);
}