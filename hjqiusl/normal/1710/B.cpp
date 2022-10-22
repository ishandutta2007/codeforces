// Lynkcat.
// Problem: B. Rain
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
#define N 600005
using namespace std;
int n,m;
pa c[N];
int cnt;
int x[N],p[N];
int st[N][21],st1[N][21];
pa g[N];
int pre[N],suf[N];
void BellaKira()
{
	cnt=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>p[i];
		c[++cnt]=mp(x[i]-p[i],1ll);
		c[++cnt]=mp(x[i],-2ll);
		c[++cnt]=mp(x[i]+p[i],1ll);
	}
	sort(c+1,c+cnt+1);
	int l=1;
	int k=0,b=0;
	int tt=0;
	for (int i=1;i<=cnt;i++)
	{
		if (i>1&&c[i].fi==c[i-1].fi) continue;
		while (l<=cnt&&c[l].fi<=c[i].fi)
		{
			k+=c[l].se;
			b+=-c[i].fi*c[l].se;
			l++;
		}
		int y=k*c[i].fi+b;
		g[++tt]=mp(c[i].fi,y);
		// cout<<tt<<","<<c[i].fi<<" "<<y<<endl;
	}
	int ans=0;
	for (int i=1;i<=tt;i++) pre[i]=max(pre[i-1],g[i].se);
	suf[tt+1]=0;
	for (int i=tt;i>=1;i--) suf[i]=max(suf[i+1],g[i].se);
	
	for (int i=1;i<=tt;i++) st[i][0]=g[i].se-g[i].fi;
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=tt;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=1;i<=tt;i++) st1[i][0]=g[i].se+g[i].fi;
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=tt;j++)
			st1[j][i]=max(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(g+1,g+tt+1,mp(x[i]-p[i],-3ll))-g;
		int mid=lower_bound(g+1,g+tt+1,mp(x[i],-3ll))-g;
		int r=lower_bound(g+1,g+tt+1,mp(x[i]+p[i],-3ll))-g;
		// cout<<"!"<<i<<" "<<pre[l-1]<<" "<<suf[r+1]<<endl;
		if (pre[l-1]>m||suf[r+1]>m) 
		{
			cout<<0;
			continue;
		}
		int t,v;
		t=log2(mid-l+1);v=max(st[l][t],st[mid-(1<<t)+1][t]);
		// cout<<"?"<<v+x[i]-p[i]<<" "<<v<<endl;
		if (v+x[i]-p[i]>m) 
		{
			cout<<0;
			continue;
		}
		l=mid,mid=r;
		t=log2(mid-l+1);v=max(st1[l][t],st1[mid-(1<<t)+1][t]);
		if (v-x[i]-p[i]>m) 
		{
			cout<<0;
			continue;
		}
		cout<<1;
	}
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