// Hydro submission #62ef227a74296d3511bba8c9@1659839098500
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,a,i;
    cin>>t;
    while(t--)
    {
        cin>>n;s=0;
        for(i=1;i<=n;i++)
        cin>>a,s|=a;
        printf("%d\n",s);
    }
    return 0;
}