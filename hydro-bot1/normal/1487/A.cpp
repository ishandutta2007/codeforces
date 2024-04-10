// Hydro submission #6274cdecbda16328ffbafb71@1651822060985
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        for(j=0;j<n;j++)
        if(a[j]==a[0]) s++;
        else break;
        printf("%d\n",n-s);
    }
    return 0;
}