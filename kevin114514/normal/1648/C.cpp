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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
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
int s[200200],t[200200];
ll fact[200200];
ll C(int n,int k)
{
	return fact[n]*ksm(fact[k],mod-2)%mod*ksm(fact[n-k],mod-2)%mod;
}
int cnt[200200];
int bit[200200];
void update(int x,int v)
{
	while(x<200200)
	{
		bit[x]+=v;
		x+=(x&(-x));
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=bit[x];
		x-=(x&(-x));
	}
	return ans;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<200200;i++)
		fact[i]=fact[i-1]*i%mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),
		cnt[s[i]]++;
	for(int i=1;i<=m;i++)
		scanf("%d",t+i);
	for(int i=1;i<=200000;i++)
		update(i,cnt[i]);
	ll tot=1;
	ll ans=0;
	int tmp=n;
	for(int i=1;i<=200000;i++)
	{
		tot=tot*C(tmp,cnt[i])%mod;
		tmp-=cnt[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(i>n)
			ans=(ans+1)%mod;
		int x=query(t[i]-1);
//		cout<<ans<<" "<<tot<<" "<<x<<endl;
		ans+=tot*x%mod*ksm((n-i+1),mod-2)%mod;
		ans%=mod;
		if(!cnt[t[i]])
			break;
		cnt[t[i]]--;
		update(t[i],-1);
		tot=tot*ksm((n-i+1),mod-2)%mod*(cnt[t[i]]+1)%mod;
	}
	cout<<ans<<endl;
	return 0;
}