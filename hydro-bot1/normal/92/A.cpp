// Hydro submission #6253b44eca53060146714b88@1649652815424
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    cin>>n>>m;
    for(;;)
    {
        for(i=1;i<=n;i++)
        if(m-i>0) m-=i;
        else if(m==i)
        {
            printf("0\n");
            return 0;
        }
        else
        {
            printf("%d\n",m);
            return 0;
        }
    }
    return 0;
}