#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb(a) push_back(a);
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int v=0;
		bool f=1;
		FOR(i,0,n)
		{
			if(s[i]=='(')
			{
				v++;
			}
			else
			{
				if(f)
				{
					f=0;
				}
				else
				{
					v--;
				}
			}
			if(v<0)
			{
				cout<<"No";
				return 0;
			}
		}
		if(f==0)
		v--;
		if(v==0)
		cout<<"Yes";
		else
		cout<<"No";
	}
	return 0;
}