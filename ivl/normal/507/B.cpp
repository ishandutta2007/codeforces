#include <cstdio>
#include <cmath>

using namespace std;

long long sq(long long x){return x * x;}
long long d(long long x, long long y, long long xx, long long yy){return sq(x - xx) + sq(y - yy);}
int r, x, y, xx, yy;

int main(){
    scanf("%d%d%d%d%d", &r, &x, &y, &xx, &yy);
    long long a = d(x, y, xx, yy);
    double aa = sqrt(a);
    r *= 2;
    aa -= 1e-6;
    long long R = ceil(aa / r) + 1e-5;
    printf("%I64d\n", R);
    return 0;
}