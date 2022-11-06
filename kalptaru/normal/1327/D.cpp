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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	
	while(test--)
	{
		int n;
		cin>>n;
		int p[n];
		int c[n];
		FOR(i,0,n)
		{
			cin>>p[i];
			p[i]--;
		}
		FOR(i,0,n)
		{
			cin>>c[i];
			c[i]--;
		}
		vector<int> cycle;
		bool visited[n]={0};
		int index=0;
		int count=n;
		int ans=n;
		int length=0;
		int start=0;
		while(1)
		{
//			cout<<count<<'c';
			if(visited[index]==0)
			{
				cycle.pb(index);
				visited[index]=1;
				count--;
				length++;
				index=p[index];
			}
			else
			{
//				cout<<count<<'c';
				FOR(i,1,min(length+1,ans))
				{
					bool check;
					if(length%i==0)
					{
//						cout<<i<<'l';
						FOR(j,0,i)
						{
							check=1;
							int col=c[cycle[j]];
							for(int k=j;k<length;k+=i)
							{
								if(c[cycle[k]]!=col)
								{
									check=0;
									break;
								}
							}
							if(check)
							{
								ans=min(ans,i);
//								cout<<i<<'k';
								break;
							}
						}
					}
				}
				if(ans==1)
				break;
				cycle.clear();
				length=0;
				while(visited[start])start++;
				index=start;
				if(count==0)
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}