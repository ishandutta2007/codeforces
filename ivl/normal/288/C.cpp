#include <cstdio>

using namespace std;

long long f(long long n){return n * (n + 1);}
int mb[1000005];

void pr(int a){printf("%d ", a);}

void printer(int n){
     if (n == 0){pr(0); return;}
     int x = (1 << mb[n]);
     
     for (int i = 0; i < x; ++i){
         int y = x - i - 1;
         int z = y + x;
         if (z <= n) pr(z); else pr(y);
     }
     
     printer(n - x);
}

int main(){
    for (int i = 2; i <= 1000000; ++i) mb[i] = 1 + mb[i / 2];
    int n;
    scanf("%d", &n);
    printf("%I64d\n", f(n));
    printer(n);
    printf("\n");
    return 0;
}