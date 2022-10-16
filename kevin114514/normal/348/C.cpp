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
ll a[100100];
vector<int> S[100100];
ll sum[100100];
ll delta[100100];
const int Sqrt=340;
vector<int> large,small;
bool type[100100];
char op[10];
int overlap[100100][Sqrt+10];
int cnt[100100];
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>Sqrt)
		{
			large.pb(i);
			type[i]=1;
		}
		else	small.pb(i);
		while(x--)
		{
			int y;
			scanf("%d",&y);
			S[i].pb(y);
			sum[i]+=a[y];
		}
	}
	for(int i=0;i<sz(large);i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(auto p:S[large[i]])
			cnt[p]++;
		for(int j=1;j<=m;j++)
			for(auto p:S[j])
				overlap[j][i]+=cnt[p];
	}
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='?')
		{
			int p;
			scanf("%d",&p);
			if(!type[p])
			{
				ll ans=0;
				for(int i=0;i<sz(S[p]);i++)
					ans+=a[S[p][i]];
				for(int i=0;i<sz(large);i++)
					ans+=delta[large[i]]*overlap[p][i];
				printf("%lld\n",ans);
			}
			else	printf("%lld\n",sum[p]);
		}
		else
		{
			int p;
			ll x;
			scanf("%d%lld",&p,&x);
			if(!type[p])
			{
				for(auto p1:S[p])
					a[p1]+=x;
				for(int i=0;i<sz(large);i++)
					sum[large[i]]+=overlap[p][i]*x;
			}
			else
			{
				delta[p]+=x;
				for(int i=0;i<sz(large);i++)
					sum[large[i]]+=overlap[p][i]*x;
			}
		}
	}
	return 0;
}