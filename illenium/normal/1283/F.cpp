#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

int a[maxn],vis[maxn];

int main()
{
	int n=read(),cnt=0;
	for(int i=1;i<n;i++) a[i]=read();
	int cur=n; vis[a[1]]=1;
	printf("%d\n",a[1]);
	for(int i=2;i<n;i++)
	{
		while(vis[cur]==1) cur--;
		while(a[i]!=cur&&vis[a[i]]==0&&i<n)
		{
			printf("%d %d\n",a[i],a[i-1]);;
			vis[a[i]]=1; vis[a[i-1]]=1; i++;
		}
		printf("%d %d\n",a[i-1],cur);
		vis[a[i-1]]=1; vis[cur]=1;
	}
	while(vis[cur]==1&&cur>=0) cur--; if(cur!=0) printf("%d %d\n",a[n-1],cur);
	return 0;
}