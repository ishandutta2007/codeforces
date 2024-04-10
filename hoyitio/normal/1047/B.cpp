#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int maxn;
    int a,b;
    scanf("%d%d",&a,&b);
    maxn = a+b;
    int t = 0;
    for(int i = 1 ; i < n ; i++)
    {
        scanf("%d%d",&a,&b);
        t=a+b;
        maxn = max(maxn,t);
    }
    printf("%d",maxn);
    return 0;
}