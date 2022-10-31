// Hydro submission #6274d00e997df5291339dae5@1651822607649
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        if(n==1) printf("1\n");
        else if(n==2) printf("-1\n");
        else
        {
            for(j=1;j<=n*n;j+=2)
            {
                printf("%d ",j);
                s++;if(s==n)
                s=0,cout<<endl;
            }
            for(j=2;j<=n*n;j+=2)
            {
                printf("%d ",j);
                s++;if(s==n)
                s=0,cout<<endl;
            }
        }
    }
    return 0;
}