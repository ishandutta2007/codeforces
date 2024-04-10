// Hydro submission #6274ced3bda16328ffbafcd3@1651822291698
#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],m[101];
int main()
{
    int t,n,i,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=1;j<=n;j++)
        cin>>a[j]>>b[j];
        for(j=1;j<=n;j++)
        cin>>m[j];
        for(j=1;j<n;j++)
        {
            s+=a[j]-b[j-1]+m[j]+(b[j]-a[j]+1)/2;
            s=max(s,b[j]);
        }
        s+=a[n]-b[n-1]+m[n];
        printf("%d\n",s);
    }
    return 0;
}