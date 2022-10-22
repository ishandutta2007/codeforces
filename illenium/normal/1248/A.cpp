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

ll a[maxn],b[maxn],fa[2],fb[2];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]&1) fa[0]++;
			else fa[1]++;
		}
		int m=read();
		for(int i=1;i<=m;i++)
		{
			b[i]=read();
			if(b[i]&1) fb[0]++;
			else fb[1]++;
		}
		cout<<(ll)(fa[0]*fb[0])+(ll)(fa[1]*fb[1])<<endl;
		fa[0]=fb[0]=fa[1]=fb[1]=0;
	}
	return 0;
}