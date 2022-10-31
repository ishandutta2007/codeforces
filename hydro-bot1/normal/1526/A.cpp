// Hydro submission #6274d083bda16328ffbafe51@1651822723970
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<2*n;j++)
        cin>>a[j];
        sort(a,a+2*n);
        for(j=0;j<n;j++)
        printf("%d %d ",a[j],a[j+n]);
        cout<<endl;
    }
    return 0;
}