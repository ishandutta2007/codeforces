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
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int d=0,md=0;
		FOR(i,0,n)
		{
			if(s[i]=='(')d++;
			else d--;
			md=max(md,d);
		}
		int a=md/2;
		FOR(i,0,n)
		{
			if(s[i]=='(')
			{
				d++;
				if(d>a)
				cout<<1;
				else
				cout<<0;
			}
			else 
			{
				if(d>a)
				cout<<1;
				else
				cout<<0;
				d--;
			}
			
		}
		
	}
	return 0;
}