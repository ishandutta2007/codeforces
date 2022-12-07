#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long int n,k;
    scanf("%I64d%I64d",&n,&k);
    long long int d=(n)/(2*(k+1));
    long long int c=k*d;
    long long int w=n-(d+c);
    printf("%I64d %I64d %I64d",d,c,w);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}