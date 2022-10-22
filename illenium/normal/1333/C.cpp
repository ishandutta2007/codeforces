#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],pre[maxn],ans,nw;
map <ll,ll> p;

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	p[0]=1; nw=0;
	for(int i=1;i<=n;i++)
	{
		nw=max(nw,p[pre[i]]);
		ans+=i-nw;
		p[pre[i]]=i+1; //cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}