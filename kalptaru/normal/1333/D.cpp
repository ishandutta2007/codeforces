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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int t=0;
		int o=0;
//		vector<int> p;
		FOR(i,0,n)
		{
			if(s[n-i-1]=='L')
			{
				o++;
			}
			else
			{
				t+=o;
			}
		}
		if(k>t)
		{
			cout<<-1;
			return 0;
		}
		vector<int> ans[k];
		int l=k,r=t;
//		cout<<t;
		while(l>0)
		{
			l--;
//			cout<<l;
			FOR(j,0,n-1)
			{
				if(s[j]=='R' && s[j+1]=='L')
				{
					ans[k-l-1].pb(j);
					r--;
					if(r==l)
					break;
				}
			}
			FOR(j,0,ans[k-l-1].size())
			{
				swap(s[ans[k-l-1][j]],s[ans[k-l-1][j]+1]);
			}
			if(r==l)
			break;
		}
		if(r>0 && l==0)
		{
			cout<<-1;
			return 0;
		}
		FOR(i,0,k-l)
		{
			cout<<ans[i].size();
			FOR(j,0,ans[i].size())
			{
				cout<<' '<<ans[i][j]+1;
			}
			cout<<'\n';
		}
		o=0;
		FOR(i,1,n+1)
		{
			if(s[n-i]=='L')
			{
				o++;
			}
			else
			{
				FOR(j,0,o)
				{
					cout<<1<<' '<<n-i+j+1<<'\n';
				}
			}
		}
	}
	return 0;
}