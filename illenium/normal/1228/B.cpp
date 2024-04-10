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
#define modc 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],b[maxn],tmp;
ll ans;
int p[1005][1005];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			p[i][j]=1;
		}
		p[i][a[i]+1]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=b[i];j++)
		{
			if(p[j][i]==0)
			{
				puts("0");
				return 0;
			}
			else p[j][i]=1;
		}
		if(b[i]+1<=n&&p[b[i]+1][i]==1)
		{
			puts("0");
			return 0;
		}
		p[b[i]+1][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p[i][j]==-1) tmp++;
		}
	}
	ans=1;
	for(int i=1;i<=tmp;i++) ans=(ans*2)%modc;
	cout<<ans<<endl;
	return 0;
}