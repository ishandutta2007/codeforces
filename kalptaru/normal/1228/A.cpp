#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
typedef long long int ll;
using namespace std;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int l,r;
		cin>>l>>r;
		int o,p;
		bool f=1;
		bool c[10]={0};
		vector<int>ans;
		FOR(i,l,r+1)
		{
			o=i;
			f=1;
			while(o>0)
			{
				p=o%10;
				if(c[p]==0)
				{
					c[p]=1;
					ans.push_back(p);
				}
				else
				{
					f=0;
					break;
				}
				o=o/10;
			}
			if(f)
			{
				p=ans.size();
				FOR(j,0,p)
				cout<<ans[p-j-1];
				return 0;
			}
			else
			{
				ans.clear();
				FOR(i,0,10)
				c[i]=0;
			}
		}
		cout<<-1;
	}
	return 0;
}