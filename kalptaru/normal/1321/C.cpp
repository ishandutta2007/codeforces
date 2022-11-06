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
ll INF=1e18;
char l[26]={'a','b','c','d','e','f','g','h','i','j','k','l','n','p','q','r','s','t','u','v','w','x','y','z'};
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
		string s;
		cin>>s;
		bool g[n]={0};
		int ans=0;
		FORD(i,25,-1)
		{
			FOR(j,0,n)
			{
				bool f=1;
				FOR(k,0,n)
				{
					if(g[k]==0 && (s[k]-'a')==i)
					{
//						cout<<k<<' '<<l[i]<<'\n';
						int m=k+1;
						while(g[m] && m<n)
						m++;
						if(m<n && (s[m]-'a')==(i-1))
						{
							g[k]=1;
							f=0;
							ans++;
							break;
						}
						m=k-1;
						while(g[m] && m>=0)
						m--;
						if(m>=0 && (s[m]-'a')==(i-1))
						{
							g[k]=1;
							f=0;
							ans++;
							break;
						}
					}
				}
				if(f)
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}