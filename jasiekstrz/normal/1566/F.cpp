#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N=2e5;
const long long INFL=1e18L+7;
const long long INF=1e9+7;
vector<long long> p;
vector<pair<long long,long long>> seg;
bool er[N+10];
long long l[N+10];
long long r[N+10];
long long dp[N+10][2][2]; // 0-l, 1-r
long long solve()
{
	long long n,m;
	cin>>n>>m;
	p.resize(n);
	seg.resize(m);
	for(long long i=0;i<n;i++)
		cin>>p[i];
	for(long long i=0;i<m;i++)
	{
		cin>>seg[i].fi>>seg[i].se;
		er[i]=false;
	}
	sort(p.begin(),p.end());
	sort(seg.begin(),seg.end(),[](pair<long long,long long> a,pair<long long,long long> b){ 
		return (a.se==b.se ? a.fi>b.fi:a.se<b.se);
	});
	long long mn=-INF;
	for(size_t i=0,j=0;i<seg.size();i++)
	{
		if(seg[i].fi<=mn)
			er[i]=true;
		else
		{
			mn=seg[i].fi;
			while(j<n && p[j]<mn)
				j++;
			if(j<n && p[j]<=seg[i].se)
				er[i]=true;
		}
	}
	for(long long i=0;i<m;)
	{
		if(er[i])
		{
			swap(er[i],er[m-1]);
			swap(seg[i],seg.back());
			seg.pop_back();
			m--;
		}
		else
			i++;
	}
	sort(seg.begin(),seg.end());
	for(long long i=0,j=-1,k=0;i<m;i++)
	{
		while(j+1<n && p[j+1]<seg[i].fi)
			j++;
		while(k<n && p[k]<=seg[i].se)
			k++;
		l[i]=(j!=-1 ? p[j]:INF);
		r[i]=(k!=n ? p[k]:INF);
		//cerr<<seg[i].fi<<" "<<seg[i].se<<" "<<l[i]<<" "<<r[i]<<"\n";
	}

	if(l[0]==INF)
		dp[0][0][0]=dp[0][0][1]=INFL;
	else
	{
		dp[0][0][0]=seg[0].fi-l[0];
		dp[0][0][1]=2LL*dp[0][0][0];
	}
	if(r[0]==INF)
		dp[0][1][0]=dp[0][1][1]=INFL;
	else
	{
		dp[0][1][1]=r[0]-seg[0].se;
		dp[0][1][0]=2LL*dp[0][1][1];
	}
	for(long long i=1;i<m;i++)
	{
		for(long long ty:{0,1})
		{
			// l
			if(l[i]==INF)
				dp[i][0][ty]=INFL;
			else if(l[i-1]==l[i])
				dp[i][0][ty]=dp[i-1][0][ty]+(long long)(seg[i].fi-seg[i-1].fi)*(ty+1);
			else if(r[i-1]==l[i])
				dp[i][0][ty]=(long long)(seg[i].fi-l[i])*(ty+1)+min({
						dp[i-1][0][0],dp[i-1][0][1],dp[i-1][1][ty]});
			else
				dp[i][0][ty]=(long long)(seg[i].fi-l[i])*(ty+1)+min({
						dp[i-1][0][0],dp[i-1][0][1],dp[i-1][1][0],dp[i-1][1][1]});
			// r
			if(r[i]==INF)
				dp[i][1][ty]=INFL;
			else
			{
				dp[i][1][ty]=(long long)(r[i]-seg[i].se)*(1+(ty+1)%2)+min({
						dp[i-1][0][0],dp[i-1][0][1]});
				if(r[i-1]==r[i])
					dp[i][1][ty]=min(dp[i][1][ty],dp[i-1][1][ty]);
				else
					dp[i][1][ty]=min(dp[i][1][ty],(long long)(r[i]-seg[i].se)*(1+(ty+1)%2)+min({
								dp[i-1][1][0],dp[i-1][1][1]}));
			}
			dp[i][0][ty]=min(dp[i][0][ty],INFL);
			dp[i][1][ty]=min(dp[i][1][ty],INFL);
		}
	}
	long long ans=INFL;
	for(long long lr:{0,1})
	{
		for(long long ty:{0,1})
			ans=min(ans,dp[m-1][lr][ty]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long qq;
	cin>>qq;
	while(qq--)
		cout<<solve()<<"\n";
	return 0;
}