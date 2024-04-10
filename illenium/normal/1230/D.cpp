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

ll n,nw;
ll a[maxn],b[maxn],ans;
map <ll,int> p;
vector <ll> vec;
bool vis[maxn];

inline void sol(ll x)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if((a[i]|x)==x)
		{
			ans+=b[i];
			vis[i]=1;
		}
	}
	return;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++)
	{
		p[a[i]]++;
		if(p[a[i]]==2) vec.push_back(a[i]);
	}
	for(int i=0;i<vec.size();i++) sol(vec[i]);
	cout<<ans<<endl;
	return 0;
}