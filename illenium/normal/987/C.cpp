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
#define maxn 3005
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

int n,a[maxn],c[maxn],mn[maxn],ans=inf;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++)
	{
		mn[i]=inf;
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j]) mn[i]=min(mn[i],c[j]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j]&&mn[j]!=inf)
				ans=min(ans,c[i]+c[j]+mn[j]);
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}