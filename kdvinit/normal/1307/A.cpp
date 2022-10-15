/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,d;
    cin>>n>>d;

    int a[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int x=a[i],y=i-1;
        if(x*y>d)
        {
            ans+=(d/y);
            break;
        }
        ans+=x;
        d-=x*y;
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}