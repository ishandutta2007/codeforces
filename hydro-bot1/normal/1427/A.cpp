// Hydro submission #6274caf7bda16328ffbaf7a8@1651821304141
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
    int t,n,i,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            s+=a[j];
        }
        sort(a,a+n);
        if(s>0)
        {
            printf("YES\n");
            for(j=n-1;j+1;j--)
            printf("%d ",a[j]);
        }
        else if(s<0)
        {
            printf("YES\n");
            for(j=0;j<n;j++)
            printf("%d ",a[j]);
        }
        else printf("NO");
        cout<<endl;
    }
    return 0;
}