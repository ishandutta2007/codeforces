#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
#define mod 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll x,k;

inline ll pw(ll a,ll b)
{
	ll res=1,base=a;
	while(b)
	{
		if(b&1) res=(res*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return res;
}

int main()
{
	cin>>x>>k;
	if(!k||!x) cout<<2ll*(x%mod)%mod;
	else x%=mod,cout<<(2ll*(pw(2ll,k)*x%mod-pw(2ll,k-1)+mod)%mod+1ll)%mod; 
	return 0;
}