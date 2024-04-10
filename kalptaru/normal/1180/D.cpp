#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,g;
	cin>>n>>m;
	g=m>>1;
	for( int i=0;i<g;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<j+1<<' '<<i+1<<"\n";
			cout<<n-j<<' '<<m-i<<"\n";
		}
	}
	if(m%2==1)
	{
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				cout<<(i>>1)+1<<' '<<g+1<<"\n";
			}
			else
			cout<<n-(i>>1)<<' '<<g+1<<"\n";
		}
	}
	return 0;
}