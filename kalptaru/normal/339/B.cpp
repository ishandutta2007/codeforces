#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll ans=0;
	int n,m,t,p=1;
	cin>>n>>m;
	for(int i =0;i<m;i++)
	{
		cin>>t;
		if(t-p<0)ans+=(n-p+t);
		else ans+=t-p;
		p=t;
	}
	cout<<ans;
	return 0;
}