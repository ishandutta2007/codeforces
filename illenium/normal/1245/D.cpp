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
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{ll x,y,w,k;}p[maxn];
ll w[maxn],tmp,pre[maxn],cnt2;
bool vis[maxn],vis2[maxn];

vector <int> ans1;

inline ll dis(node a,node b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
	for(int i=1;i<=n;i++) p[i].w=read();
	for(int i=1;i<=n;i++) p[i].k=read();
	for(int i=1;i<=n;i++) w[i]=p[i].w;
	for(int i=1;i<=n;i++)
	{
		ll ans=inf,fl=1;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			else if(w[j]<ans) ans=w[j],fl=j;
		}
		vis[fl]=1; tmp+=w[fl];
		if(vis2[fl]==0) ans1.push_back(fl);
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(w[j]>(p[fl].k+p[j].k)*dis(p[fl],p[j]))
			{
				w[j]=(p[fl].k+p[j].k)*dis(p[fl],p[j]);
				vis2[j]=1; pre[j]=fl;
			}
		}
	}
	cout<<tmp<<endl;
	cout<<ans1.size()<<endl;
	for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]); cout<<endl;
	for(int i=1;i<=n;i++) if(vis2[i]==1) cnt2++;
	cout<<cnt2<<endl;
	for(int i=1;i<=n;i++) if(vis2[i]==1) printf("%d %d\n",i,pre[i]);
	return 0;
}