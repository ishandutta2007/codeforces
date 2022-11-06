#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;
ll mo=1000000007;
bool bm[5210][5210];
int o[23]={0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15};
int gcd(int a,int b)
{
	if(a<b)
	swap(a,b);
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		int w=n/4;
		string m[n];
		ll has[n];
		int g=n;
		FOR(i,0,n)
		{
			cin>>m[i];
			FOR(j,0,w)
			{
				int u=o[m[i][j]-'0'],r=3;
				while(r>=0)
				{
					bm[i][4*j+r]=(u%2);
					u>>=1;
					r--;
				}
			}
		}
		FOR(i,0,n)
		{
			int cnt=0;
			bool tem=bm[i][0];
			FOR(j,0,n)
			{
				if(bm[i][j]==tem)
				cnt++;
				else
				{
					g=gcd(cnt,g);
					cnt=1;
					tem=tem^1;
				}
			}
			g=gcd(g,cnt);
		}
		FOR(j,0,n)
		{
			int cnt=0;
			bool tem=bm[0][j];
			FOR(i,0,n)
			{
				if(bm[i][j]==tem)
				cnt++;
				else
				{
					g=gcd(cnt,g);
					cnt=1;
					tem=tem^1;
				}
			}
			g=gcd(g,cnt);
		}
		cout<<g;
	}
	return 0;
}