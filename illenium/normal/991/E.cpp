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

string n;
int d[20],len,cnt[10];
ll f[25],tp[25],ans;

inline void dfs(ll x,ll y)
{
	if(x==10)
	{
		ll s=1,tmp=y,p=y;
		for(int i=0;i<=9;i++)
			if(tp[i]) s=s*f[tmp]/f[tp[i]]/f[tmp-tp[i]],tmp-=tp[i];
		if(tp[0]) s-=s*tp[0]/y;
		ans+=s;
		return;
	}
	for(int i=1;i<=cnt[x];i++)
	{
		tp[x]=i;
		dfs(x+1,y+i);
	}
	if(cnt[x]==0) dfs(x+1,y);
}

int main()
{
	cin>>n;
	f[0]=f[1]=1;
	for(int i=2;i<=20;i++) f[i]=i*f[i-1];
	for(int i=0;i<n.length();i++) cnt[n[i]-'0']++;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}