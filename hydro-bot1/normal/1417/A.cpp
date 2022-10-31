// Hydro submission #6274ca7c997df5291339cb8f@1651821181117
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int t,n,k,i,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;s=0;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        for(j=1;j<n;j++)
        s+=(k-a[j])/a[0];
        printf("%d\n",s);
    }
    return 0;
}