#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if((n%3)!=2)
    {
        printf("1 1 %d\n",n-2);
    }
    if((n%3)==2)
    {
        printf("1 2 %d\n",n-3);
    }
    return 0;
}