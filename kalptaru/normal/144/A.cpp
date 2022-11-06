#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t;
	cin>>n;
	int u=0,d=101,ui,di;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t>u)
		{
			u=t;
			ui=i;
		}
		if(t<=d)
		{
			d=t;
			di=i;
		}
	}
	t=ui+n-di-1;
	if (t>=n)
	t-=1;
	cout<<t;
	return 0;
}