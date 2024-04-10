#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long in[100005];
/*
bool cmp(const long long &a, const long long &b){return a > b;}

bool pred(long long t){
     long long p1, p2;
     p1 = t;
     p2 = 0;
     for (int i = 0; i < n; ++i){
         printf("%I64d %I64d\n", p1, p2);
         if (p2 < in[i]){
            long long x = in[i] - p2;
            if (x > p1) return false;
            p1 -= x;
            p2 += x * (n - 1);
         }
         p2 -= in[i];
     }
     return true;
}*/

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", in + i);
    /*sort(in, in + n, cmp);
    long long lo = 0, hi = 1000000000000LL, mid = (lo + hi) / 2;
    while (lo != hi){
          if (pred(mid)){
             hi = mid;
          }
          else {
               lo = mid + 1;
          }
          mid = (lo + hi) / 2;
    }
    printf("%d\n", (int)pred(3));
    printf("%I64d\n", mid);*/
    long long suma = 0, maks = 0;
    for (int i = 0; i < n; ++i){
        suma += in[i];
        if (maks < in[i]) maks = in[i];
    }
    suma = (suma + n - 2) / (n - 1);
    if (suma > maks) printf("%I64d\n", suma);
    else printf("%I64d\n", maks);
    return 0;
}