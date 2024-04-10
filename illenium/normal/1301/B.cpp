#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9+7
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++) a[i]=read(); a[n+1]=0;
		vector <int> vec; vec.clear();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1) continue;
			if(a[i+1]==-1||a[i-1]==-1) vec.push_back(a[i]);
		}
		for(int i=2;i<=n;i++) if(a[i]!=-1&&a[i-1]!=-1) ans=max(ans,abs(a[i]-a[i-1]));
		if(vec.size()==0)
		{
			printf("%d %d\n",ans,0);
			continue;
		}
		int mx=-inf,mn=inf;
		for(int i=0;i<vec.size();i++) mx=max(mx,vec[i]),mn=min(mn,vec[i]);
		ans=max(ans,mx-(mx+mn)/2);
		printf("%d %d\n",ans,(mx+mn)/2);
	}
	return 0;
}