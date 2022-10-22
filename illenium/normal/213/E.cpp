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
#define ull unsigned long long
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

int n,m,pos[maxn],x,ans;
ull xp[maxn],val,sum;

struct node
{
	ull hash,cnt;
}tree[maxn<<2];

void build(int o,int l,int r)
{
	tree[o].hash=tree[o].cnt=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

inline void pushup(int o)
{
	tree[o].hash=tree[o<<1].hash*xp[tree[o<<1|1].cnt]+tree[o<<1|1].hash;
	tree[o].cnt=tree[o<<1].cnt+tree[o<<1|1].cnt;
}

void update(int o,int l,int r,int pos,int val,int num)
{
	if(l==r)
	{
		tree[o].hash+=num*val;
		tree[o].cnt+=num;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(o<<1,l,mid,pos,val,num);
	else update(o<<1|1,mid+1,r,pos,val,num);
	pushup(o);
}

int main()
{
	n=read(); m=read();
	val=sum=0; xp[0]=1;
	for(int i=1;i<=n;i++) xp[i]=xp[i-1]*233,sum+=xp[i-1];
	for(int i=1;i<=n;i++) x=read(),val=val*233+x;
	for(int i=1;i<=m;i++) x=read(),pos[x]=i;
	build(1,1,m);
	for(int i=1;i<=m;i++)
	{
		update(1,1,m,pos[i],i,1);
		if(i>=n)
		{
			if(tree[1].hash-(sum*(i-n))==val) ans++;
			update(1,1,m,pos[i-n+1],i-n+1,-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}