#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n;
	cin>>a;
	ll ans=a+2*n-1;
	for(int i=1;i<n;i++)
	{
		cin>>b;
		ans+= (b>=a ? b-a : a-b);
		a=b;
	}
	cout<<ans;
	return 0;
}