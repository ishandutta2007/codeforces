#include <cstdio>
#include <iostream>

using namespace std;

long long n, m;
long long xc, yc;
long long k;
long long dx[10005], dy[10005];

long long rez;

long long calc(long long x, long long y){
    if (x == 0){
       if (y < 0){
          long long r = - (yc - 1) / y;
          yc += r * y;
          return r;
       }
       else {
            long long r = (m - yc) / y;
            yc += r * y;
            return r;
       }
    }
    if (x < 0){
       long long r1 = - (xc - 1) / x;
       if (y == 0){
          xc += r1 * x;
          return r1;
       }
       if (yc + r1 * y <= 0){
          long long r2 = - (yc - 1) / y;
          yc += r2 * y;
          xc += r2 * x;
          return r2;
       }
       if (yc + r1 * y > m){
          long long r2 = (m - yc) / y;
          yc += r2 * y;
          xc += r2 * x;
          return r2;
       }
       yc += r1 * y;
       xc += r1 * x;
       return r1;
    }
    else {
         long long r1 = (n - xc) / x;
         if (y == 0){
            xc += r1 * x;
            return r1;
         }
         if (yc + r1 * y <= 0){
            long long r2 = - (yc - 1) / y;
            yc += r2 * y;
            xc += r2 * x;
            return r2;
         }
         if (yc + r1 * y > m){
            long long r2 = (m - yc) / y;
            yc += r2 * y;
            xc += r2 * x;
            return r2;
         }
         yc += r1 * y;
         xc += r1 * x;
         return r1;
    }
}

int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d", &n, &m, &xc, &yc, &k);
    for (long long i = 0; i < k; ++i){
        scanf("%I64d%I64d", dx + i, dy + i);
    }
    for (long long i = 0; i < k; ++i){
        rez += calc(dx[i], dy[i]);
    }
    printf("%I64d\n", rez);
    return 0;
}