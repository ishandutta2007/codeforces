// Hydro submission #6297291bb0c5e75beb15815c@1654073628440
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int t,n,h,s,m,c,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>h;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        m=h%(a[n-1]+a[n-2]);
        c=h/(a[n-1]+a[n-2])*2;
        printf("%d\n",m?(m>a[n-1]?c+2:c+1):c);
    }
    return 0;
}