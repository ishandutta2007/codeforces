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

int n,m,a[maxn],b[maxn];

int main()
{
	n=read(); m=read();
	int f=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]+=b[i-1]+f*(a[i]-a[i-1]);
		f^=1;
	}
	b[n+1]=b[n]+f*(m-a[n]);
	int ans=b[n+1];
	for(int i=1;i<=n;i++)
		ans=max(ans,b[i]+m-a[i]-(b[n+1]-b[i])-1);
	cout<<ans<<endl;
	return 0;
}