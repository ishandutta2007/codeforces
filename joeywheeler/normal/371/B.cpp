#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int a[2];
int y[2][3];
int x[] = {2, 3, 5};

int main() {
    scanf("%d %d", &a[0], &a[1]);

    FO(i,0,3)
        FO(j,0,2) {
            while (a[j] % x[i] == 0) {
                a[j] /= x[i];
                y[j][i]++;
            }
        }

    if (a[0] != a[1])
        printf("-1\n");
    else {
        int res = 0;
        FO(i,0,3)
            res += abs(y[0][i] - y[1][i]);
        printf("%d\n", res);
    }

    return 0;
}