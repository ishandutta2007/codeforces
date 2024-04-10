#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b,k,x,n=0;
    scanf("%d%d",&b,&k);
    for(int i=1;i<k;i++)
    {
        scanf("%d",&x);
        n=(n+b*x)%2;
    }
    scanf("%d",&x);
    n=(n+x)%2;
    if(n) printf("odd");
    else printf("even");
}