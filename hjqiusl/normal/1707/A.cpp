// Lynkcat.
// Problem: A. Doremy's IQ
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/0
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
#define N 100005
using namespace std;
int n,q,a[N],suf[N];
int ans[N];
void BellaKira()
{
	cin>>n;cin>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int nw=0;
	for (int i=n;i>=1;i--)
	{
		if (nw==q)
		{
			if (a[i]>nw) ans[i]=0;
			else ans[i]=1;
			continue;
		}
		if (a[i]>nw)
		{
			ans[i]=1;
			nw++;
		} else
		{
			ans[i]=1;
		}
	}
	for (int i=1;i<=n;i++) cout<<ans[i];
	cout<<endl;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}