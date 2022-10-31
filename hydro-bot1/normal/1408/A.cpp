// Hydro submission #6274c9fd997df5291339c95f@1651821054147
#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100],s[100];
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
        cin>>b[j];
        for(j=0;j<n;j++)
        cin>>c[j];
        s[0]=a[0];
        for(j=1;j<n-1;j++)
        if(a[j]-s[j-1])
        s[j]=a[j];
        else if(b[j]-s[j-1])
        s[j]=b[j];
        else s[j]=c[j];
        if(s[n-2]-a[n-1]&&s[0]-a[n-1])
        s[n-1]=a[n-1];
        else if(s[n-2]-b[n-1]&&s[0]-b[n-1])
        s[n-1]=b[n-1];
        else s[n-1]=c[n-1];
        for(j=0;j<n;j++)
        printf("%d ",s[j]);
        cout<<endl;
    }
    return 0;
}