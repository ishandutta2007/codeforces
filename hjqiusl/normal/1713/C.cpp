// Lynkcat.
// Problem: C. Build Permutation
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
#define N 200005
using namespace std;
int n,f[N],vis[N],b[N];
void BellaKira()
{
	cin>>n;
	int nn=n;
	n--;
	poly g;
	while (n!=-1)
	{
		int nxt=f[n];
		// cout<<n<<","<<f[n]<<endl;
		for (int i=nxt+1;i<=n;i++) g.push_back(i);
		n=nxt;
	}
	reverse(g.begin(),g.end());
	for (auto u:g) cout<<u<<" ";
	cout<<endl;
}
signed main()
{
	n=100000;
	f[0]=-1;
	vis[0]=1;
	b[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j*j<=2*n;j++)
		{
			int x=j*j-i;
			// cout<<"?"<<i<<" "<<x<<endl;
			if (x<0||x>i) continue;
			f[i]=x-1;
		}
	}
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}