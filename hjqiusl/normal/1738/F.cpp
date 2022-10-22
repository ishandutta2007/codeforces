// Lynkcat.
// Problem: F. Connectivity Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2005
using namespace std;
int n,d[N],col[N];
int qry(int x)
{
	cout<<"? "<<x<<endl;
	int res=0;
	cin>>res;
	return res;
}
void BellaKira()
{
	int tot=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>d[i],col[i]=0;
	while (1)
	{
		int now=0;
		for (int i=1;i<=n;i++)
			if (!col[i])
			{
				if (!now||d[i]>d[now]) now=i;
			}
		if (!now) break;
		poly g;
		g.push_back(now);
		while (d[now]--)
		{
			int x=qry(now);
			if (x==-1)
			{
				break;
			} else
			{		
				if (col[x]) 
				{
					for (auto u:g)
						col[u]=col[x];
					break;
				}
				else g.push_back(x);
			}
		}
		if (!col[now])
		{
			++tot;
			for (auto u:g) col[u]=tot;
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<col[i]<<" ";
	cout<<endl;
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}