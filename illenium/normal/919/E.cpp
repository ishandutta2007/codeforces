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
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a,b,p,x;

inline ll qpow(ll x,ll y,ll p)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res;
}

int main()
{
	cin>>a>>b>>p>>x;
	ll ans=0,tmp=a;
	for(ll i=1;i<=p-1;i++,tmp=(tmp*a)%p)
	{
		ll c=b*qpow(tmp,p-2,p)%p;
		ll k=(i-c+p)%p;
		ll minn=i+k*(p-1);
		if(minn>x) continue;
		ans+=(x-minn)/(p*(p-1))+1;
	}
	cout<<ans<<endl;
	return 0;
}