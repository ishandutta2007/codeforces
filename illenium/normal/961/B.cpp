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
#define maxn 100005
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

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int n,m,k,ans=-1;
int sa[maxn],a[maxn],sb[maxn],b[maxn];

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sa[i]=sa[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++) sb[i]=sb[i-1]+b[i]*a[i];
	for(int i=1;i<=n-k+1;i++)
	{
		int l=i,r=i+k-1;
		int pre=sb[r]-sb[l-1];
		int now=sa[r]-sa[l-1];
		ans=max(ans,sb[n]-pre+now);
	}
	cout<<ans<<endl;
	return 0;
}