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

int a[maxn],b[maxn],c[maxn],d[maxn],cnt,dp[maxn],ans;

int main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=k;i++) c[i]=read();
	sort(a+1,a+n+1); sort(b+1,b+m+1); sort(c+1,c+k+1);
	for(int i=1;i<=n;i++) d[++cnt]=a[i];
	for(int i=1;i<=m;i++) d[++cnt]=b[i];
	for(int i=1;i<=k;i++) d[++cnt]=c[i];
	for(int i=1;i<=cnt;i++)
	{
		if(d[i]>dp[ans]) dp[++ans]=d[i];
		else dp[lower_bound(dp+1,dp+ans+1,d[i])-dp]=d[i];
		
	}
	cout<<n+m+k-ans<<endl;
	return 0;
}