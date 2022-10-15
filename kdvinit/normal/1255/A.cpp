/*
K.D. Vinit
*/
#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    long long int a,b,ans;
    cin>>a>>b;
    a=abs(a-b);

    ans=a/5;
    a%=5;
    ans+=(a+1)/2;

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