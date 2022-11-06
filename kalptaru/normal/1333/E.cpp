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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		if(n<3)
		{
			cout<<-1;
			return 0;
		}
		if(n==3)
		{
			cout<<"5 2 9"<<'\n';
			cout<<"7 4 3"<<'\n';
			cout<<"6 1 8";
			return 0;
		}
		int ans[n][n];
		FOR(i,0,n-4)
		{
			FOR(j,0,n)
			{
				if((i+n)%2==0)
				{
					ans[i][j]=n*i+j+1;
				}
				else
				{
					ans[i][n-j-1]=n*i+j+1;
				}
			}
		}
		int u=n*(n-4)+1;
		FOR(i,0,n-4)
		{
			ans[n-4][i]=u;
			u++;
		}
		FOR(i,0,n-4)
		{
			ans[n-3][n-i-5]=u;
			u++;
		}
		FOR(i,0,n-4)
		{
			ans[n-1][i]=u;
			u++;
		}
		FOR(i,0,n-4)
		{
			ans[n-2][n-i-5]=u;
			u++;
		}
		u--;
		int b[4][4];
		b[0][0]=4;
		b[0][1]=3;
		b[0][2]=6;
		b[0][3]=12;
		b[1][0]=7;
		b[1][1]=5;
		b[1][2]=9;
		b[1][3]=15;
		b[2][0]=14;
		b[2][1]=1;
		b[2][2]=11;
		b[2][3]=10;
		b[3][0]=13;
		b[3][1]=8;
		b[3][2]=16;
		b[3][3]=2;
		FOR(i,n-4,n)
		{
			FOR(j,n-4,n)
			{
				ans[i][j]=u+b[i-n+4][j-n+4];
			}
		}
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}