#include <cstdio>
#include <cmath>

using namespace std;

int m, n;

double cnt(double x){
       x /= m;
       return pow(x, (double)n);
}

int main(){
    scanf("%d%d", &m, &n);
    double r = 0;
    for (int i = 1; i <= m; ++i){
        r += i * (cnt(i) - cnt(i - 1));
    }
    printf("%lf\n", r);
    return 0;
}