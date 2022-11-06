#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t,m;
	ll v=0,p=0;
	cin>>n;
	int x[n];
	for(int i=0;i<n;i++)
	{
		cin>>t;
		x[t-1]=i;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>t;
		v+=(x[t-1]+1);
		p+=(n-x[t-1]);
	}
	cout<<v<<' '<<p;
	
	return 0;
}