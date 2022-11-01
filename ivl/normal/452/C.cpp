#include <cstdio>

using namespace std;

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    if (n == 1){printf("1.0000\n"); return 0;}
    if (m == 1){printf("%lf\n", 1.0 / n); return 0;}
    double r = 0;
    double curr = 1;
    for (int i = 1; i <= n; ++i){
        curr *= (n - 1) * m - n + i;
        curr /= n * m - n + i;
    }
    for (int i = 0; i <= m; ++i){
        //printf(" - %lf\n", curr);
        r += curr * i * i / n;
        curr *= m - i;
        curr /= i + 1;
        curr *= n - i;
        curr /= (n - 1) * m - n + i + 1;
    }
    printf("%lf\n", r);
    return 0;
}