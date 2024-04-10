#include <cstdio>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int n, d;
int x[100005];

long long f(long long k) {
    return ((k-1)*(k-2))/2;
}

int main() {
    scanf("%d %d", &n, &d);
    FO(i,0,n) scanf("%d", x+i);

    int o = 0;

    long long res = 0;
    FO(i,0,n) {
        while (o < n && x[o]-x[i] <= d) o++;
        res += f(o-i);
    }
    printf("%I64d\n", res);

    return 0;
}