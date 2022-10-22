#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,b[maxn],ans[maxn],suf[maxn];
const ll mod=998244353;

int main()
{
	cin>>n; b[0]=1;
	for(int i=1;i<=maxn-5;i++) b[i]=(b[i-1]*10)%mod;
	ll nw=0,tot=0;
	for(ll i=n;i>=1;i--)
	{
		nw=(nw+suf[i+1])%mod;
		tot=((n-i+1)*b[n-i+1])%mod;
		ans[i]=(tot-nw+mod)%mod; nw=(nw+ans[i])%mod; suf[i]=(suf[i+1]+ans[i])%mod;
	}
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]); puts("");
	return 0;
}