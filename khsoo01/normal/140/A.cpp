#include<bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
long double n, a, b;

int main()
{
    int N, A, B;
    scanf("%d%d%d",&N,&A,&B);
    n = N; a = A; b = B;
    if(a+(1e-9) <= b) {puts("NO"); return 0;}
    if(a < 2*b) {puts(n<=1?"YES":"NO"); return 0;}
    long double X = asin(b/(a-b));
    puts(PI/X>=n?"YES":"NO");
}