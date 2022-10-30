// Hydro submission #62fb45f34b7288bafe609bd3@1660634611451
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,y,mxx,mxy,mnx,mny,i;
    cin>>t;
    while(t--)
    {
        cin>>n;mxx=0,mxy=0,mnx=0,mny=0;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            mxx=max(mxx,x);
            mxy=max(mxy,y);
            mnx=min(mnx,x);
            mny=min(mny,y);
        }
        printf("%d\n",2*(mxx+mxy-mnx-mny));
    }
    return 0;
}