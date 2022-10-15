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
const ll mod=998244353;
ll fact[100100];
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return ksm(a*a%mod,b/2)*a%mod;
	return ksm(a*a%mod,b/2);
}
ll C(ll a,ll b)
{
	if(b<0||a<b)
		return 0ll;
	return fact[a]*ksm(fact[b],mod-2)%mod*ksm(fact[a-b],mod-2)%mod;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<100100;i++)
		fact[i]=fact[i-1]*i%mod;
	int n;
	cin>>n;
	int lw=0,lb=0,rw=0,rb=0;
	int bw=0,wb=0;
	ll x=1;
	bool fl=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(s[0]==s[1]&&s[0]!='?')
			fl=1;
//		cout<<s<<endl;
		if(s[0]=='W')
		{
			lw++;
			wb++;
		}
		if(s[0]=='B')
		{
			lb++;
			bw++;
		}
		if(s[1]=='W')
		{
			rw++;
			bw++;
		}
		if(s[1]=='B')
		{
			rb++;
			wb++;
		}
		if(s=="??")
			x=(x+x)%mod;
	}
	ll ans=0;
//	cout<<lw<<" "<<lb<<" "<<rw<<" "<<rb<<endl;
	for(int i=0;i<=n;i++)
	{
		ans+=C(n-lw-lb,i-lw)*C(n-rw-rb,i-rb)%mod;
//		cout<<i<<" "<<n-lw-lb<<" "<<i-lw<<" "<<n-rw-rb<<" "<<i-rb<<endl;
		ans%=mod;
	}
	if(!wb)
		wb=1;
	else	wb=0;
	if(!bw)
		bw=1;
	else	bw=0;
	if(!fl)
		cout<<(ans-x+wb+bw)%mod<<endl;
	else	cout<<ans<<endl;
	return 0;
}