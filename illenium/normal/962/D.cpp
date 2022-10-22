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

map <ll,int> mp;
int n,ans;
ll a[maxn];

int main()
{
	n=read(); ans=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		while(mp[a[i]])
		{
			a[mp[a[i]]]=0;
			mp[a[i]]=0;
			a[i]+=a[i];
			--ans;
		}
		mp[a[i]]=i;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) if(a[i]) cout<<a[i]<<" ";
	return 0;
}