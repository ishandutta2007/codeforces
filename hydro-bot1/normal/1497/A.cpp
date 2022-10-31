// Hydro submission #6274ce97bda16328ffbafc9f@1651822232029
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        printf("%d",a[0]);
        for(j=1;j<n;j++)
        if(a[j]-a[j-1]) printf(" %d",a[j]);
        for(j=1;j<n;j++)
        if(a[j]==a[j-1]) printf(" %d",a[j]);
        cout<<endl;
    }
    return 0;
}