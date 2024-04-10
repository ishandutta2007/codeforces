#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,q,m;
int a[300005];

int len[300005];
long long ans[300005];
vector<int> qry[300005];

vector<pair<int,int> > v[300005];
vector<long long> s[300005];

int mi[300005][19],b[300005];

void solve()
{
	int i,j;
	scanf("%d%d%d",&n,&q,&m);
	rep(i,n) scanf("%d",&a[i]);
	
	rep(i,n) mi[i][0]=a[i];
	rep(j,18) rep(i,n-(1<<j)+1) mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	
	int ss=0;
	while((1<<ss)<=m) ss++;
	ss--;
	for(i=m;i<=n;i++) b[i]=min(mi[i-m+1][ss],mi[i-(1<<ss)+1][ss]);
	
	for(i=0;i<m;i++)
	{
		v[i].push_back(make_pair((n-i)/m+1,0));
		s[i].push_back(0);
	}
	
	rep(i,q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
/*		ans[i]=a[l];
		l+=m;
		
		if(l>r) continue;*/
		len[i]=(r-l)/m+1;
		qry[l].push_back(i);
	}
	
	for(i=n;i>=1;i--)
	{
		int t=i%m;
		
		while(v[t].back().second>=a[i])
		{
			v[t].pop_back();
			s[t].pop_back();
		}
		
		s[t].push_back(s[t].back()+1ll*(v[t].back().first-i/m)*a[i]);
		v[t].push_back(make_pair(i/m,a[i]));
		
		while(!qry[i].empty())
		{
			int j=qry[i].back();
			qry[i].pop_back();
			ans[j]+=s[t].back();
			
			int l=0,r=v[t].size(),mid;
			while(l<r)
			{
				mid=(l+r)/2;
				if(v[t][mid].first>=i/m+len[j]) l=mid+1; else r=mid;
			}
			
			ans[j]-=s[t][l-1];
			if(l<v[t].size()) ans[j]-=1ll*v[t][l].second*(v[t][l-1].first-(i/m+len[j]));
		}
		
		if(i<m) continue;
		while(v[t].back().second>=b[i])
		{
			v[t].pop_back();
			s[t].pop_back();
		}
		
		s[t].push_back(s[t].back()+1ll*(v[t].back().first-i/m)*b[i]);
		v[t].push_back(make_pair(i/m,b[i]));
	}
	
	rep(i,q)
	{
		printf("%lld\n",ans[i]);
	}
}

int main()
{
	solve();
	return 0;
}