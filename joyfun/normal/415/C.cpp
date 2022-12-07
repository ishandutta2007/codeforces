#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    if (n == 1) {
        if (k == 0) {
            printf("1\n");
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    if (n / 2 > k) printf("-1\n");
    else {
        int sb = k - (n - 2) / 2;
        printf("%d %d", sb, sb * 2);
        int num = sb * 2 + 1;
        for (int i = 0; i < n - 2; i++) {
            printf(" %d", num); num++;
        }
        printf("\n");
    }
    return 0;
}