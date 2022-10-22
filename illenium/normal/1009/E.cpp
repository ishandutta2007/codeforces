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
#define maxn 10000010
#define re register
#define inf 1e9
#define eps 1e-10
#define mod 998244353
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll d,a[maxn],p[maxn],n,ans;

inline void up(ll &a)
{
	if(a>=mod) a-=mod;
}

int main()
{
	n=read(); p[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]<<1,up(p[i]),a[i]=read();
	for(int i=1;i<=n-1;i++)
		d=(((a[i]*(n-i+2))%mod)*p[n-i-1])%mod,ans+=d,up(ans);
	ans+=a[n]; up(ans);
    cout<<ans;
	return 0;
}