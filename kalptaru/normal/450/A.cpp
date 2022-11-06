#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,t,l=0,li=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>t;
		if(t%m==0)
		t=t/m;
		else
		t=t/m+1;
		if(t>=l)
		{
			l=t;
			li=i;
		}		
	}
	cout<<li;
	return 0;
}