#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int n, k;
int a[104];
int b[3];

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,n) scanf("%d", &a[i]);
    int res = 0;
    FO(i,0,k) {
        b[1] = b[2] = 0;
        for (int j = i; j < n; j += k) {
            b[a[j]]++;
        }
        res += min(b[1], b[2]);
    }
    printf("%d\n", res);

    return 0;
}