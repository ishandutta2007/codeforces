#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
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

int a[maxn],b[maxn],c[maxn],cnt,tot,t[maxn];

inline void add(int x){for(int i=x;i<=tot;i+=i&-i) t[i]++;}
inline ll q(int x)
{
	ll res=0;
	for(int i=x;i;i-=i&-i) res+=t[i];
	return res;
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read(),c[++cnt]=a[i]-b[i],c[++cnt]=b[i]-a[i];
	sort(c+1,c+cnt+1);
	tot=unique(c+1,c+cnt+1)-c-1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int p1=a[i]-b[i],p2=b[i]-a[i];
		int x1=lower_bound(c+1,c+tot+1,p1)-c,x2=lower_bound(c+1,c+tot+1,p2)-c;
		ans+=q(x1-1); add(x2); //cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}