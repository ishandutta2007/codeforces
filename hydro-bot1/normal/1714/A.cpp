// Hydro submission #62fb469a4b7288bafe609d64@1660634778463
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,a,b,h,m,mn,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        s=0,mn=1439;
        for(i=1;i<=n;i++)
        {
            cin>>h>>m;
            s=(h-a)*60+m-b;
            if(a>h||a==h&&b>m)
            s+=1440;
            mn=min(mn,s);
        }
        printf("%d %d\n",mn/60,mn%60);
    }
    return 0;
}