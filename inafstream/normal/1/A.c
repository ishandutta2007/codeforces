#include<stdio.h>

long long n,m,k;

int main (){
    
    scanf("%d%d%d", &n, &m, &k);
    printf("%I64d\n", ( ( n + k - 1) / k ) * ( ( m + k - 1 ) / k ) );
    
}