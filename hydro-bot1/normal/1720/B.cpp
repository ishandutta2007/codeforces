// Hydro submission #631f2e85bdf9bc31d15c7fcf@1662987910634
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+n+1);
        printf("%d\n",a[n]+a[n-1]-a[1]-a[2]);
    }
    return 0;
}