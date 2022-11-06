#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,m,ans,y;
	cin>>n>>m>>k;
	ans=m;
	ll a[m],f,x;
	for(int i=0;i<m;i++)
	cin>>a[i];
	cin>>f;
	for(int i=0;i<m;i++)
	{
		y=0;
		x=a[i]^f;
		while(x)
		{
			if(x%2)
			{
				y++;
				if(y>k)
				{
					ans--;
					break;
				}
			}
			x=x>>1;
		}
	}
	cout<<ans;
	return 0;
}