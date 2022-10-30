// Hydro submission #631f3055bdf9bc31d15c8348@1662988374196
#include<bits/stdc++.h>
using namespace std;
int a[2001];
int main()
{
    int t,n,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n,s=0;
        for(i=1;i<=n;i++)
        cin>>a[i];
        for(i=1;i<=n;i++)
        s=max(max(max(a[n]-a[i],a[i]-a[1]),a[i>1?i-1:n]-a[i]),s);
        printf("%d\n",s);
    }
    return 0;
}