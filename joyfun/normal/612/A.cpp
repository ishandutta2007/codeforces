#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, p, q;
char str[105];

int main() {
    scanf("%d%d%d", &n, &p, &q);
    scanf("%s", str);
    for (int i = 0; i * p <= n; i++) {
        if ((n - i * p) % q == 0) {
            printf("%d\n", i + (n - i * p) / q);
            int u = 0;
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < p; k++)
                    printf("%c", str[u++]);
                printf("\n");
            }
            for (int j = 0; j < (n - i * p) / q; j++) {
                for (int k = 0; k < q; k++)
                    printf("%c", str[u++]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}