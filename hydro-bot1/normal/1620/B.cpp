// Hydro submission #62ef22c874879b352565dcd3@1659839177706
#include<bits/stdc++.h>
using namespace std;
int a[5][200001];
int main()
{
    long long w,h,mx;
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>w>>h;mx=0;
        for(i=1;i<=4;i++)
        {
            cin>>a[i][0];
            for(j=1;j<=a[i][0];j++)
            cin>>a[i][j];
            mx=max(mx,(a[i][a[i][0]]-a[i][1])*(i<3?h:w));
        }
        printf("%lld\n",mx);
    }
    return 0;
}