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

ll n,tmp,ans;
int a[maxn],cnt,flag,b[maxn];

inline void clear()
{
	for(int i=1;i<=cnt+1;i++) b[i]=0;
	for(int i=1;i<=cnt;i++) a[i]=0;
}

int main()
{
	int T=read();
	while(T--)
	{
		cin>>n; flag=0; tmp=n; ans=0; cnt=0; ll base=1;
		while(n)
		{
			a[++cnt]=n%3;
			n/=3;
		}
		for(int i=1;i<=cnt+1;i++) b[i]=0;
		for(int i=cnt;i>=1;i--) if(a[i]==2) {flag=i; break;}
		if(flag==0) {printf("%lld\n",tmp); clear(); continue;} flag++;
		while(a[flag]==1) flag++; b[flag]=1;
		for(int i=flag+1;i<=cnt;i++) b[i]=a[i];
		for(int i=1;i<=cnt+1;i++)
		{
			ans+=(base*b[i]);
			base*=3;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=cnt;i++) a[i]=0;
		for(int i=1;i<=cnt+1;i++) b[i]=0;
	}
	return 0;
}