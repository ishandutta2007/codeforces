// Hydro submission #62ef224074879b352565dbf3@1659839041233
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,mx,mn,p,q,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0,mn=101,p=0,q=0;
        for(i=1;i<=n;i++)
        {
            cin>>a;
            if(a>mx) mx=a,p=i;
            if(a<mn) mn=a,q=i;
        }
        printf("%d\n",min(min(min(q+n-p+1,p+n-q+1),max(p,q)),max(n-p+1,n-q+1)));
    }
    return 0;
}