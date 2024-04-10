/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n,r,ans=0;
    cin>>n>>r;
    r=min(r,n);

    if(r>=n)
    {
        ans=(n)*(n-1);
        ans/=2;
        ans+=1;
    }
    else
    {
        ans=(r)*(r+1);
        ans/=2;
    }

    cout<<ans<<endl;
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