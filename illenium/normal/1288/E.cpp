#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
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

vector <int> p[maxn];
int a[maxn],vis[maxn],ans1[maxn],ans2[maxn],cnt,c[maxn],t[maxn],n,m,vis2[maxn],pre[maxn];

struct node{int l,r,id;}q[maxn];

inline void add(int x,int val){for(int i=x;i<=3e5;i+=i&-i) c[i]+=val;}
inline int query(int x){int tmp=0; for(int i=x;i;i-=i&-i) tmp+=c[i]; return tmp;}

inline bool cmp(node a,node b){return a.r<b.r;}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++) a[i]=read(),vis[a[i]]=1,p[a[i]].push_back(i);
	for(int i=1;i<=n;i++) if(vis[i]) ans1[i]=1; else ans1[i]=i;
	for(int i=1;i<=n;i++) p[i].push_back(m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<p[i].size();j++)
		{
			q[++cnt]=(node){p[i][j-1],p[i][j],i};
		}
	}
	sort(q+1,q+cnt+1,cmp);
	
	for(int i=1;i<=3e5;i++) c[i]=0;
	for(int i=1;i<=m;i++)
	{
		if(vis2[a[i]]) continue;
		vis2[a[i]]=1; add(a[i],1); ans2[a[i]]=a[i]+query(n)-query(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(ans2[i]==0) ans2[i]=i+query(n)-query(i);
		ans2[i]=max(ans2[i],i);
	}
	for(int i=1;i<=3e5;i++) c[i]=0;
	
	//for(int i=1;i<=cnt;i++) cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].id<<endl;
	
	int r=0;
	for(int i=1;i<=cnt;i++)
	{
		while(r<q[i].r)
		{
			r++; if(pre[a[r]]!=0) add(pre[a[r]],-1);
			pre[a[r]]=r; add(r,1);
		}
		ans2[q[i].id]=max(ans2[q[i].id],query(q[i].r)-query(q[i].l-1));
	}
	//cout<<query(20)<<" "<<query(4)<<endl;
	
	for(int i=1;i<=n;i++) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}