#include <cstdio>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x[1000];
    for (int i = 1; i <= n; i++) x[i] = i%2 == 1 ? n*(i-1)+1 : n*i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", x[j]);
        }
        printf("\n");
        for (int j = 1; j <= n; j++) {
            if (j%2 == 1) x[j]++;
            else x[j]--;
        }
    }

    return 0;
}