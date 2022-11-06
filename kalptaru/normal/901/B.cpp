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

ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
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
		int a[n+1][n+1];
		a[0][0]=1;
		a[1][0]=0;
		a[1][1]=1;
		FOR(i,2,n+1)
		{
			FOR(j,0,i+1)
			{
				a[i][j]=((j>0?a[i-1][j-1]:0)+(j<(i-1)?a[i-2][j]:0))%2;
//				cout<<((j>0)?a[i-1][j-1]:0)<<'k';
			}
//			cout<<'\n';
		}
		cout<<n<<'\n';
		FOR(i,0,n+1)
		cout<<a[n][i]<<' ';
		cout<<'\n'<<n-1<<'\n';
		FOR(i,0,n)
		cout<<a[n-1][i]<<' ';
	}
	return 0;
}