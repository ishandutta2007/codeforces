#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct Suf
{
	pair<int,int> w;
	int id;
	inline bool operator<(const Suf &oth)
	{
		if(w==oth.w)
			return id>oth.id;
		return w<oth.w;
	}
};
char c[200010];
bool ok[200010];
Suf suf[200010];
int g[400010];
int pref[200010];
int lcp[200010];
int last[200010];
stack<int> stck;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,j;
	long long ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=1;i<=n;i++)
	{
		char tmp;
		cin>>tmp;
		ok[i]=(tmp=='0');
	}
	reverse(c+1,c+n+1);
	reverse(ok+1,ok+n+1);
	for(i=1;i<=n;i++)
	{
		suf[i].id=i;
		suf[i].w={(int)c[i],(int)c[i]};
	}
	sort(suf+1,suf+n+1);
	for(j=2;j<2*n;j*=2)
	{
		//for(i=1;i<=n;i++)
		//	cerr<<suf[i].id<<" ";
		//cerr<<"\n";
		//for(i=1;i<=n;i++)
		//	cerr<<suf[i].id<<"("<<suf[i].w.fi<<","<<suf[i].w.se<<") ";
		//cerr<<"\n";
		int xd=1;
		//suf[1].w.fi=xd;
		g[suf[1].id]=xd;
		for(i=2;i<=n;i++)
		{
			if(suf[i].w!=suf[i-1].w)
				xd++;
			//suf[i].w.fi=xd;
			g[suf[i].id]=xd;
		}
		for(i=1;i<=n;i++)
			suf[i].w={g[suf[i].id],g[suf[i].id+j/2]};
		sort(suf+1,suf+n+1);
	}
	for(i=1;i<=n;i++)
	{
		g[suf[i].id]=i;
		pref[i]=pref[i-1]+ok[suf[i].id];
		lcp[i]=0;
	}
	lcp[0]=0;
	for(i=1;i<=n;i++)
	{
		lcp[g[i]]=max(0,lcp[g[i-1]]-1);
		//cerr<<i<<" "<<lcp[g[i]]<<"\n";
		while(c[i+lcp[g[i]]]==c[suf[g[i]+1].id+lcp[g[i]]])
			lcp[g[i]]++;
	}
	/*for(i=1;i<=n;i++)
		cout<<suf[i].id<<" "<<lcp[i]<<" "<<pref[i]<<"\n";*/
	for(i=1;i<=n;i++)
	{
		if(ok[i])
		{
			ans=n-i+1;
			break;
		}
	}
	lcp[0]=-1;
	stck.push(0);
	for(i=1;i<=n;i++)
	{
		while(lcp[stck.top()]>=lcp[i])
		{
			int x=stck.top();
			stck.pop();
			ans=max(ans,(long long)lcp[x]*(pref[i]-pref[last[x]]));
			//cerr<<ans<<" "<<x<<" "<<last[x]<<" "<<i<<"\n";
		}
		last[i]=stck.top();
		stck.push(i);
	}
	cout<<ans<<"\n";
	return 0;
}