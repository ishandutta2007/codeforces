#include <stdio.h>
#include <string.h>
#include <math.h>2 
#define min(a,b) ((a)<(b)?(a):(b))
int c, d, n, m, k;

int main() {
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int sb = n * m - k;
    if (sb <= 0) printf("0\n");
    else printf("%d\n", min(sb * d, min((int)ceil(sb * 1.0 / n) * c, sb / n * c + sb % n * d)));
    return 0;
}