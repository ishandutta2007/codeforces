#include <cstdio>
#include <algorithm>

int n;

int main(){
    scanf("%d", &n);
    printf("%I64d", (2ll << n) - 2);
}