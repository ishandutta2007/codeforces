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
		int n,m;
		cin>>n>>m;
		if(n==1 && m==1)
		{
			cout<<"YES\n1";
			return 0;
		}
		if(n==3 && m==3)
		{
			cout<<"YES\n2 9 4\n7 5 3\n6 1 8";
			return 0;
		}
		if(max(n,m)<4)
		{
			cout<<"NO";
			return 0;
		}
		cout<<"YES"<<'\n';
		int ans[n][m];
		if(m>=n)
		{
			if(m==4)
			{
				FOR(i,0,n)
				{	
					if(i%2==0)
					{
						ans[i][0]=i*m+3;
						ans[i][1]=i*m+1;
						ans[i][2]=i*m+4;
						ans[i][3]=i*m+2;
					}
					else
					{
						ans[i][3]=i*m+3;
						ans[i][2]=i*m+1;
						ans[i][1]=i*m+4;
						ans[i][0]=i*m+2;
					}
				}
			}
			else
			{
				FOR(i,0,n)
				{
					FOR(j,0,m)
					{
						if(i%2==0)
						{
							if(j%2==0)
							{
								ans[i][j]=i*m+((j+2)/2);
							}
							else
							{
								ans[i][j]=i*m+((j+2)/2)+(m+1)/2;
							}
						}
						else
						{
							if(j%2==1)
							{
								ans[i][j]=i*m+((j+2)/2);
							}
							else
							{
								ans[i][j]=i*m+((j+2)/2)+m/2;
							}
						}
					}
				}
			}
		}
		else
		{
			if(n==4)
			{
				FOR(i,0,m)
				{	
					if(i%2==0)
					{
						ans[0][i]=2*m+i+1;
						ans[1][i]=i+1;
						ans[2][i]=3*m+1+i;
						ans[3][i]=m+1+i;
					}
					else
					{
						ans[3][i]=2*m+i+1;
						ans[2][i]=i+1;
						ans[1][i]=3*m+1+i;
						ans[0][i]=m+1+i;
					}
				}
			}
			else
			{
				FOR(j,0,n)
				{
					FOR(i,0,m)
					{
						if(i%2==0)
						{
							if(j%2==1)
							{
								ans[j][i]=i+1+(((j+2)/2)-1)*m;
							}
							else
							{
								ans[j][i]=i+1+(((j+2)/2)+n/2-1)*m;
							}
						}
						else
						{
							if(j%2==0)
							{
								ans[j][i]=i+1+(((j+2)/2)-1)*m;
							}
							else
							{
								ans[j][i]=i+1+(((j+2)/2)+(n+1)/2-1)*m;
							}
						}
					}
				}
			}
		}
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}