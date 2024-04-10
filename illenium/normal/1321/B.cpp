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

ll a[maxn],b[maxn],c[maxn],cnt[maxn],ans;

int main()
{
	ll n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i]-i+2e5; //cout<<b[i]<<endl;
	}
	for(int i=1;i<=n;i++) cnt[b[i]]++,c[b[i]]+=(i-2e5);
	for(int i=0;i<=8e5;i++) ans=max(ans,cnt[i]*i+c[i]);
	cout<<ans<<endl;
	return 0;
}