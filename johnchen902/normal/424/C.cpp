#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int xors[1000001];

int main() {
    int n;
    scanf("%d", &n);
    int v = 0;
    for(int j = 1; j <= n; j++){
        xors[j] = xors[j - 1] ^ j;
//        printf("xors[%d]=%d\n", j, xors[j]);
        int t = 0;
        int i;
        for(i = 1; i + j - 1 <= n; i += j)
            t ^= xors[j - 1];
//            for(int k = 1; k < j; k++)
//                t ^= k % j;
        t ^= xors[n % j];
//        printf("%d: [n%%j=%d] ", j, n%j);
//        for(; i <= n; i++)
//            printf("%d ", i % j), t ^= i % j;
//        printf("\n");
        v ^= t;
    }
    for(int i = 0; i < n; i++){
        int w;
        scanf("%d", &w);
        v ^= w;
    }
    printf("%d\n", v);
}