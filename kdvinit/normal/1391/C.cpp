/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    long long int mod=1e9+7,ans1=1,ans2=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        ans1*=i;
        ans1%=mod;
    }
    for(int i=1;i<n;i++)
    {
        ans2*=2;
        ans2%=mod;
    }

    ans=ans1-ans2;
    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--) solve();
	return 0;
}