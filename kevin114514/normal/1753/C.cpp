//Author: Kevin5307
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
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
const ll mod=998244353;
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return ksm(a*a%mod,b/2)*a%mod;
	return ksm(a*a%mod,b/2);
}
int a[200200];
ll f[200200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int tot0=0,tot1=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(a[i])
				tot1++;
			else	tot0++;
		}
		int x=0;
		for(int i=1;i<=tot0;i++)
			if(a[i])
				x++;
		f[0]=0;
		for(int i=1;i<=x;i++)
		{
//			cout<<1ll*i*i%mod*ksm(1ll*n*(n-1)/2%mod,mod-2)%mod<<endl;
			f[i]=(f[i-1]+ksm((1ll*i*i%mod*ksm(1ll*n*(n-1)/2%mod,mod-2)%mod+mod)%mod,mod-2))%mod;
		}
		printf("%lld\n",f[x]);
	}
	return 0;
}