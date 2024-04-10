// Hydro submission #62972c5cb0c5e75beb158702@1654074460968
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,l,r,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>a[j];
        for(l=0;l<n&&a[l];l++);
        for(r=n;r>0&&a[r-1];r--);
        printf("%d\n",max(r+1-l,0));
        
    }
    return 0;
}