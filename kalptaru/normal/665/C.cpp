#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		int n=s.size();
		FOR(i,1,n)
		{
			if(s[i-1]==s[i])
			{
				if(s[i-1]=='a' || (i<(n-1) && s[i+1]=='a'))
				{
					if(s[i-1]=='b' || (i<(n-1) && s[i+1]=='b'))
					{
						s[i]='c';
					}
					else
					{
						s[i]='b';
					}
				}
				else
				{
					s[i]='a';
				}
			}
		}
		cout<<s;
	}
	return 0;
}