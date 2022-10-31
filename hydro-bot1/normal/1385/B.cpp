// Hydro submission #6274c940997df5291339c87b@1651820864428
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<2*n;j++)
        {
            cin>>a[j];
            for(k=0;k<j;k++)
            if(a[j]==a[k])
            {
                printf("%d ",a[j]);
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}