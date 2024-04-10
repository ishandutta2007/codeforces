// Hydro submission #6274cefdbda16328ffbafce7@1651822334251
#include<bits/stdc++.h>
using namespace std;
int a[2000];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>a[j];
        for(j=0;j<n;j++)
        if(a[j]%2)
        printf("%d ",a[j]);
        for(j=0;j<n;j++)
        if(a[j]%2==0)
        printf("%d ",a[j]);
        cout<<endl;
    }
    return 0;
}