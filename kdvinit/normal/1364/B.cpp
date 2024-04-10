/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int a[n+1],ans[n+1],cntr=0,u=0,d=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(i==n) { ans[++cntr]=a[i]; continue; }
        if(a[i+1]>a[i])
        {
            if(u==0) ans[++cntr]=a[i];
            u=1; d=0;
        }
        if(a[i+1]<a[i])
        {
            if(d==0) ans[++cntr]=a[i];
            d=1; u=0;
        }
    }

    cout<<cntr<<endl;
    for(int i=1;i<=cntr;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}