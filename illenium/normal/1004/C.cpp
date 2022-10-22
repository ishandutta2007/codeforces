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

int n,a[maxn],cnt[maxn];
bool vis[maxn];
set <int> r;
ll ans=0;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++,r.insert(a[i]);
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]--;
		if(cnt[a[i]]==0) r.erase(a[i]);
		if(vis[a[i]]) continue; vis[a[i]]=1;
		ans=(ans+r.size());
	}
	cout<<ans<<endl;
	return 0;
}