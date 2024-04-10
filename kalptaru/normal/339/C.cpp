#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb(a) push_back(a);
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
string s;
int m;
int ans[1050];
bool mi(int i,int j,int k);
bool pl(int i,int j,int k)
{
	bool v=0;
	if(k==m+1)
	{
		ans[k]=i;
		return 1;
	}
	FOR(l,0,10)
	{
		if(s[l]=='1' && i!=(l+1) && j+l+1>0)
		{
			v=v|mi(l+1,j+l+1,k+1);
			if(v)
			{
				ans[k]=i;
				return 1;
			}
		}
	}
	return 0;
}
bool mi(int i,int j,int k)
{
	bool v=0;
	if(k==m+1)
	{
		ans[k]=i;
		return 1;
	}
	FOR(l,0,10)
	{
		if(s[l]=='1' && i!=(l+1) && j-l-1<0)
		{
			v=v|pl(l+1,j-l-1,k+1);
			if(v)
			{
				ans[k]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		cin>>s>>m;
		if(pl(0,0,1))
		{
			cout<<"YES\n";
			FOR(i,2,m+2)
			cout<<ans[i]<<' ';
		}
		else
		{
			cout<<"NO";
		}
		
	}
	return 0;
}