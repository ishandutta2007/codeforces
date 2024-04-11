#include "bits/stdc++.h"

using namespace std;

const int MOD = 1000000007;

int popraw(int x)
{
    long long tx = (x+2LL*MOD)%MOD;
    return tx;
}

int main()
{
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    if(n%6==1)
        printf("%d\n", popraw(a));
    if(n%6==2)
        printf("%d\n", popraw(b));
    if(n%6==3)
        printf("%d\n", popraw(b-a));
    if(n%6==4)
        printf("%d\n", popraw(-a));
    if(n%6==5)
        printf("%d\n", popraw(-b));
    if(n%6==0)
        printf("%d\n", popraw(a-b));        
}