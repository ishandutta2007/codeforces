// Hydro submission #62972bc2b0c5e75beb1585c7@1654074307336
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n%7)
        {
            n=n/10*10;
            for(j=n;j<n+10;j++)
            if(j%7==0)
            {
                printf("%d\n",j);
                break;
            }
        }
        else printf("%d\n",n);
    }
    return 0;
}