// Lynkcat.
// Problem: B. Prefix Sum Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
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
#define N  100005
using namespace std;
int n,m,a[N],b[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i];
	if (m==1)
	{
		return cout<<"Yes"<<'\n',void();
	}
	for (int i=1;i<m;i++)
		b[n-(m-1-i)]=a[i+1]-a[i];
	int x=n-m+2;
	for (int i=x+1;i<=n;i++)
		if (b[i]<b[i-1]) return cout<<"No"<<'\n',void();
	if (x==1) return cout<<"Yes"<<'\n',void();
	if (b[x]*(x-1)>=a[1]) return cout<<"Yes\n",void();
	else cout<<"No\n",void();
		
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