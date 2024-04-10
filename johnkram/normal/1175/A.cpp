#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
int t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(ans=-1;n;n/=m,ans++)ans+=n%m;
		cout<<ans<<endl;
	}
	return 0;
}