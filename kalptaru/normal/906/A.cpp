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
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		char t;
		string s;
		bool o[26];
		FOR(i,0,26)o[i]=1;
		int c=26;
		bool f=0;
		int ans=0;
		FOR(i,0,n)
		{
			cin>>t;
			cin>>s;
			if(t=='!')
			{
				if(f)ans++;
				bool r[26]={0};
				FOR(j,0,s.size())
				{
					r[s[j]-'a']=1;	
				}
				FOR(j,0,26)
				{
					if(r[j]==0)
					{
						if(o[j]==1)
						{
							c--;
							o[j]=0;
						}
					}
				}
			}
			else if(t=='.')
			{
				FOR(j,0,s.size())
				{
					if(o[s[j]-'a']==1)
					{
						c--;
						o[s[j]-'a']=0;
					}
				}
			}
			else
			{
				if(f && i!=(n-1))ans++;
				if(o[s[0]-'a']==1)
				{
					c--;
					o[s[0]-'a']=0;
				}
			}
			if(c==1)
			f=1;
		}
		cout<<ans;
	}
	return 0;
}