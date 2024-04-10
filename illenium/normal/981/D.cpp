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

ll n,m,a[55],s[55],f[55][55],ans;

inline bool check(ll b)
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=j-1;k<i;k++)
				if(f[k][j-1]&&((s[i]-s[k])&b)==b) f[i][j]=1;
	return f[n][m];
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=a[i]+s[i-1];
	for(int i=63;i>=0;i--)
		if(check(ans|(1ll<<i))) ans|=(1ll<<i);
	cout<<ans<<endl;
	return 0; 
}