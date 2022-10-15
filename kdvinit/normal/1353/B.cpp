/*
KDVINIT

My Test Case -

Mistakes -

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,ans=0;
        cin>>n>>k;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ans+=a[i];
        }
        for(int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=k;i++)
        {
            if(a[i]<b[n+1-i]) ans=ans-a[i]+b[n+1-i];
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}