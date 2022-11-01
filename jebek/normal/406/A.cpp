#include <iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n,x,q,sum,t;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&x);
            if(i==j)
                sum+=x;
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&t);
        if(t==3)
            printf("%d",sum%2);
        else
        {
            scanf("%d",&x);
            sum++;
        }
    }
}