#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,p,d1=-1,d2=-1,x;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if((x%p)>0&&d1==-1)d1=i;
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        if((x%p)>0&&d2==-1)d2=i;
    }
    printf("%d",d1+d2);
    return 0;
}