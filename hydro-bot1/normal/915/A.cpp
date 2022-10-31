// Hydro submission #62591f3dcc64917dc466528c@1650007870364
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,a,mx=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(k%a==0)
        mx=max(mx,a);
    }
    printf("%d\n",k/mx);
    return 0;
}