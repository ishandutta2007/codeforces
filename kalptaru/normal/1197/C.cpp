#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t=1;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n],d[n-1],ans=0;
		cin>>a[0];
		for(int i=1;i<n;i++)
		{
			cin>>a[i];
			d[i-1]=a[i]-a[i-1];
		}
		ans=a[n-1]-a[0];
		sort(d,d+(n-1));
		for(int i=1;i<k;i++)
		ans-=d[n-i-1];
		cout<<ans;
	}
}