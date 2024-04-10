#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,k,p[maxn];
const ll mod=998244353;

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++) p[i]=read();
	ll lst=n-k+1,ans=0,a2=1,cnt=0,f=0;
	for(ll i=lst;i<=n;i++) ans+=i; cout<<ans<<" ";
	for(int i=1;i<=n;i++) if(p[i]>=lst) {f=i; break;}
	for(int i=f+1;i<=n;i++)
	{
		if(p[i]>=lst)
		{
			a2=(a2*(cnt+1))%mod;
			cnt=0;
		}
		else cnt++;
	}
	cout<<a2<<endl;
	return 0;
}