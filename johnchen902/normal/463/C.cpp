#include <cstdio>
#define int
using namespace std;
signed a[2000][2000]; // max 1e9
long long s1[4000], s2[4000];
signed main(){
    signed n; // max 2000
    scanf("%d", &n);
    for(signed i = 0; i < n; i++) { // index
        for(signed j = 0; j < n; j++) { // index
            scanf("%d", &a[i][j]);
            s1[i + j] += a[i][j];
            s2[i + (n - 1 - j)] += a[i][j];
        }
    }
    long long sum1 = 0, sum2 = 0;
    signed x1 = 1, y1 = 0, x2 = 0, y2 = 0; // max 2000
    for(signed i = 0; i < n; i++) // index
        for(signed j = 0; j < n; j++) { // index
            long long x = s1[i + j] + s2[i + (n - 1 - j)] - a[i][j];
            if((i + j) % 2) {
                if(x > sum1)
                    sum1 = x, x1 = i, y1 = j;
            } else {
                if(x > sum2)
                    sum2 = x, x2 = i, y2 = j;
            }
        }
    printf("%I64d\n%d %d %d %d\n", sum1 + sum2,
           x1 + 1,
           y1 + 1,
           x2 + 1,
           y2 + 1);
}