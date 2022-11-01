#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int x[105];

int main() {
    int res = 0;
    int n;
    scanf("%d", &n);

    FO(i,0,n) {
        int k;
        scanf("%d", &k);
        FO(j,0,i+1) {
            x[j] ^= k;
            res = max(res, x[j]);
        }
    }

    printf("%d\n", res);

    return 0;
}