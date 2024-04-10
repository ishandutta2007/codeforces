// Hydro submission #632dbf519efe78d183c12152@1664067596316
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls x*2
#define rs x*2+1
int n,q,a[N],p,x;
struct rua{int mn,cnt,tag;}t[N<<2];
void down(int x)
{
	int v=t[x].tag;
	t[ls].mn+=v,t[ls].tag+=v;
	t[rs].mn+=v,t[rs].tag+=v;
	t[x].tag=0;
}
void update(int x)
{
	t[x].mn=min(t[ls].mn,t[rs].mn);
	t[x].cnt=(t[ls].mn==t[x].mn)*t[ls].cnt+(t[rs].mn==t[x].mn)*t[rs].cnt;
}
void change(int i,int c,int x,int l,int r)
{
	if(l==r){t[x].cnt+=c;return;}
	down(x);
	int mid=l+r>>1;
	if(i<=mid)change(i,c,ls,l,mid);
	else change(i,c,rs,mid+1,r);
	update(x);
}
void add(int l,int r,int c,int x,int L,int R)
{
	if(l<=L && R<=r){t[x].mn+=c,t[x].tag+=c;return;}
	down(x);
	int mid=L+R>>1;
	if(l<=mid)add(l,r,c,ls,L,mid);
	if(r>mid)add(l,r,c,rs,mid+1,R);
	update(x);
}
int cnt;
void modify(int x,int y,int c)
{
	add(min(x,y)+1,max(x,y),c,1,1,N-1);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	a[0]=N-1;
	for(int i=0;i<=n;i++)
	  {
	  if(i)change(a[i],1,1,1,N-1);
	  modify(a[i],a[i+1],1);
	  }
	for(int i=1;i<=q;i++)
	  {
	  scanf("%d%d",&p,&x);
	  change(a[p],-1,1,1,N-1);
	  modify(a[p-1],a[p],-1);
	  modify(a[p],a[p+1],-1);
	  a[p]=x;
	  change(a[p],1,1,1,N-1);
	  modify(a[p-1],a[p],1);
	  modify(a[p],a[p+1],1);printf("%d\n",t[1].mn==1?t[1].cnt:0);
	  }
}