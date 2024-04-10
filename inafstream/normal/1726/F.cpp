#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,t;
int g[200005],c[200005],d[200005];

int cst(int fr,int to)
{
	int res=to-fr;
	if(res<0) res+=t;
	return res;
}

void solve()
{
	scanf("%d%d",&n,&t);
	rep(i,n) scanf("%d%d",&g[i],&c[i]);
	int s=0;long long bs=0;
	rep(i,n-1)
	{
		int x;scanf("%d",&x);s=(s+x)%t;bs+=x;
		c[i+1]=(c[i+1]+s)%t;
	}

	map<int,long long> mp;
	mp[0]=0;
	rep(i,n){
		mp[(t+g[i]-1-c[i])%t]=0;
		mp[(t-c[i])%t]=0;
	}
	rep(i,n)
	{
		int p=(t-c[i])%t;
		long long v=1e18;
		map<int,long long>::iterator it=mp.lower_bound((g[i]-c[i]+t)%t);
		while(it!=mp.end()&&(it->first+c[i])%t>=g[i])
		{
			v=min(v,it->second+cst(it->first,p));
			it=mp.erase(it);
		}
		it=mp.begin();
		while(it!=mp.end()&&(it->first+c[i])%t>=g[i])
		{
			v=min(v,it->second+cst(it->first,p));
			it=mp.erase(it);
		}
		if(v<1e18)
		{
			if(!mp.count(p)) mp[p]=v;
			else mp[p]=min(mp[p],v);
		}
	}

	long long ans=1e18;
	for(auto u:mp) ans=min(ans,u.second);
	printf("%lld\n",ans+bs);
}

int main()
{
	solve();
	return 0;
}