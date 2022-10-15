/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    long long int n,ans=0;
    cin>>n;
    while(n!=0)
    {
        ans+=n;
        n/=2;
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