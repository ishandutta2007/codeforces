#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[15];
ll dp[(1<<10)+70][(1<<10)+70];
inline void upd(ll &a,ll b)
{
	a+=b;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].pb(b);
		G[b].pb(a);
		dp[(1<<a)+(1<<b)][(1<<a)+(1<<b)]=1ll;
	}
	for(int mskall=0;mskall<(1<<n);mskall++)
		for(int msk1=0;msk1<(1<<n);msk1++)
			if(dp[mskall][msk1])
			if((mskall&msk1)==msk1)
			{
			//	cout<<"mskall:"<<mskall<<",msk1:"<<msk1<<endl;
				for(int u=0;u<n;u++) if(mskall>>u&1)
					for(auto v:G[u]) if(!(mskall>>v&1)) if((msk1&((1<<n)-1-(1<<u)))>>v<<v==(msk1&((1<<n)-1-(1<<u))))
					{
					//	cout<<"mskall:"<<mskall<<",msk1:"<<msk1<<",u:"<<u<<",v:"<<v<<endl;
						upd(dp[mskall|(1<<v)][(msk1&((1<<n)-1-(1<<u)))|(1<<v)],dp[mskall][msk1]);
			//			if(mskall|(1<<v)==(1<<n)-1)
			//				cout<<msk1<<"->"<<((msk1&((1<<n)-1-(1<<u)))|(1<<v))<<endl;
					}
			}
	ll ans=0;
	for(int msk1=0;msk1<(1<<n);msk1++)
		if(__builtin_popcount(msk1)==k)
			upd(ans,dp[(1<<n)-1][msk1]);
	cout<<ans<<endl;
	return 0;
}