#include <cstdio>
#include <algorithm>

long long n;

int main(){
    scanf("%I64d", &n); n++;
    printf("%I64d", 3ll * n * (n - 1ll) + 1);
}