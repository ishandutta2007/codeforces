#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
pair<pii,int> p[200200];
int delta[200200];
const ll mod=1000000007;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			p[i]=mp(mp(x,y),z);
		}
		ll ans=0;
		for(int i=0;i<30;i++)
		{
			for(int j=0;j<=n;j++)
				delta[j]=0;
			for(int j=1;j<=m;j++) if(!(p[j].second>>i&1))
			{
				delta[p[j].first.first]++;
				delta[p[j].first.second+1]--;
			}
			int cnt=0;
			int x=0;
			for(int j=1;j<=n;j++)
			{
				cnt+=delta[j];
				if(!cnt)
					x++;
			}
			if(x)
			{
				ll tmp=1;
				for(int j=1;j<n+i;j++)
					tmp=tmp*2%mod;
				ans=(ans+tmp)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}