// Lynkcat.
// Problem: A. Color the Picture
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/0
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
// #define N 
using namespace std;
int n,m,k,a[100005];
void BellaKira()
{
	cin>>n>>m>>k;
	int x=0,y=0;
	int tx=0,ty=0;
	for (int i=1;i<=k;i++)
	{
		cin>>a[i];
		if (a[i]/n>=2)
		{
			x+=a[i]/n;
			tx+=(a[i]/n)-2;
		}
		
		if (a[i]/m>=2)
		{
			y+=a[i]/m;
			ty+=(a[i]/m)-2;
		}
	}
	// cout<<x<<","<<y<<endl;
	if (x<m) x=-1;
	if (y<n) y=-1;
	
	if (x!=-1)
	{
		if (m%2==1&&tx==0) x=-1;
	}
	if (y!=-1) 
	{
		if (n%2==1&&ty==0) y=-1;
	}
	if (x==-1&&y==-1) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
		
	
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