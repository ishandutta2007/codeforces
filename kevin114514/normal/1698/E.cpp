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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int posa[200200],pos[200200];
int EE[200200];
int a[200200],b[200200];
const ll mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;i++)
			pos[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[i]=x;
			posa[x]=i;
		}
		ll ans=1;
		EE[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			EE[i]=1;
			int x;
			scanf("%d",&x);
			b[i]=x;
		}
		vector<int> vec;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==-1)
				vec.pb(max(a[i]-s,1));
			else if(a[i]-s>b[i])
				ans=0;
			if(b[i]!=-1)
				EE[b[i]]=0;
		}
		for(int i=n;i>=1;i--)
			EE[i]+=EE[i+1];
		rsrt(vec);
		int cnt=0;
		for(auto x:vec)
			ans=ans*(EE[x]-cnt++)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}