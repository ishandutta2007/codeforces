#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b,o;
	cin>>n>>a>>b;
	int p[n];
	for(int j=0;j<n;j++)
	cin>>p[j];
	int i=0;
	o=a;
	for(;i<n;i++)
	{
		if(o==b)
		{
			cout<<i;
			break;
		}
		else if(o==a && i>0)
		{
			cout<<-1;
			break;
		}
		o=p[o-1];
	}
	return 0;
}