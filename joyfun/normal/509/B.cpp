#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, a[105];

int main() {
    while (~scanf("%d%d", &n, &k)) {
        int Min = 105, Max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            Min = min(Min, a[i]);
            Max = max(Max, a[i]);
        }
        int use = min(k, Min);
        int one = Min / use;
        int yu = Min % use;
        if (Max - Min > k) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                printf("1");
                for (int j = 2; j <= Min; j++)
                    printf(" 1");
                for (int j = Min + 1; j <= a[i]; j++)
                    printf(" %d", j - Min);
                printf("\n");
            }
        }
    }
    return 0;
}