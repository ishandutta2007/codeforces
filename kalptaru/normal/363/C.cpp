#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int tem=1,ans=0;
		string s;
		cin>>s;
		bool f=0;
		char p=s[0];
		FOR(i,1,s.size())
		{
			if(p==s[i])
			{
				tem++;
			}
			else
			{
				if(tem>1)
				{
					if(f)
					{
						cout<<p;
						f=0;
					}
					else
					{
						cout<<p<<p;
						f=1;
					}
				}
				else
				{
					f=0;
					cout<<p;
				}
				tem=1;
				p=s[i];
			}
		}
		if(tem>1)
		{
			if(f)
			{
				cout<<p;
				f=0;
			}
			else
			{
				cout<<p<<p;
				f=1;
			}
		}
		else
		cout<<p;
	}
}