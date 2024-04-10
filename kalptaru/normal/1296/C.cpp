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
ll m1=1000000007;
ll m2=67280421310721;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		map<pair<int,int> ,ll > pt;
		int n;
		cin>>n;
		string s;
		cin>>s;
		int x=0,y=0,r;
		pt[mp(0,0)]=1;
		ll m=m1;
		FOR(i,0,n)
		{
			if(s[i]=='L')
			x--;
			else if(s[i]=='R')
			x++;
			else if(s[i]=='U')
			y++;
			else
			y--;
			if(pt[mp(x,y)]!=0)
			{
				int o=i-pt[mp(x,y)]+2;
				if(o<m)
				{
					m=o;
					r=i;
				}
			}
			pt[mp(x,y)]=i+2;
		}
		if(m==m1)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<r-m+2<<' '<<r+1<<'\n';
		}
	}
	return 0;
}