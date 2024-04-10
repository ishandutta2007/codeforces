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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn];
ll d[505][505],s[505][505];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0) n--,i--;
	}
	if(n>=300) {puts("3"); return 0;}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=inf,s[i][j]=inf;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i]&a[j]) d[i][j]=s[i][j]=d[j][i]=s[j][i]=1;
	ll ans=inf;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i) continue;
			for(int j=1;j<=n;j++)
			{
				if(j==i||j==k) continue;
				ans=min(ans,d[i][j]+s[i][k]+s[k][j]);
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				
			}
		}
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}