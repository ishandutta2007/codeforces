#pragma GCC optimize(2)
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

ll a[maxn],pos[maxn];

int main()
{
	ll T=read();
	while(T--)
	{
		ll q=read(),b=read();
		for(int i=1;i<=q;i++) a[i]=read(),pos[a[i]]=i;
		ll tmp=0,ans=0,cnt=0;
		for(int i=1;i<=b;i++)
		{
			int x=read();
			if(pos[x]<tmp) ans++,cnt++;
			else ans+=2*(pos[x]-cnt)-1,cnt++;
			tmp=max(tmp,pos[x]);
		}
		cout<<ans<<endl;
	}
	return 0;
}