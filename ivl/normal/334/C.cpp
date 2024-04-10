#include <cstdio>

using namespace std;

long long n;

long long rek(long long x){
     if (x % 3 == 0) return rek(x / 3);
     return x / 3 + 1;
}

int main(){
    scanf("%I64d", &n);
    printf("%I64d\n", rek(n));
    return 0;
}