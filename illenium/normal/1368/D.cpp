#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],ans[maxn],tot;

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	for(int x=21;x>=0;x--)
	{
		int nw=0;
		for(int i=1;i<=n;i++) if(a[i]&(1<<x)) ans[++nw]+=(1<<x);
	}
	for(int i=1;i<=n;i++) tot+=ans[i]*ans[i]; cout<<tot<<endl;
	return 0;
}