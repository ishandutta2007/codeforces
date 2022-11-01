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
pair<long long,int> x[300005];
long long cum[300005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int X;
        scanf("%d", &X);
        x[i].first = X;
        x[i].second = i;
    }
    scanf("%d", &k);

    sort(x, x+n);

    FO(i,0,n) {
        cum[i+1] = x[i].first + cum[i];
    }

    unsigned long long res;
    int bp = -1;
    unsigned long long v = 0;
    for (int i = k-1; i >= 0; i--) {
        v += (2*i+1-k) * x[i].first;
    }
    FO(i,0,n) if (i+k <= n) {
        if (bp == -1 || v < res) {
            res = v;
            bp = i;
        }
        v -= (1-k) * x[i].first;
        v += (k-1) * x[i+k].first;
        v -= 2 * (cum[i+k] - cum[i+1]);
    }
    
    FO(i,bp,bp+k) {
        printf("%d ", x[i].second+1);
    }
    printf("\n");


    return 0;
}