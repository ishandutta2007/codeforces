#include<bits/stdc++.h>
using std::sort;

const int N=5005,M=100000,U=100001;
int n,m,k,i;
struct edge
{
	int x,y,id,w;
	bool is;
	bool operator <(const edge &i)const
	{
		if(w!=i.w) return w<i.w;
		return is; 
	}
}q[M+3];
int st[N],top;
int f[N];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
int check(int w,bool can)
{
	for(i=1;i<=m;++i) 
	if(q[i].is)q[i].w-=w;
	
	int ans=0,x,y;
	sort(q+1,q+m+1);
	for(i=1;i<=n;++i) f[i]=i;
	for(top=0,i=1;i<=m;++i)
	{
		x=find(q[i].x);y=find(q[i].y); 
		if(x==y) continue;
		if(!can&&ans+q[i].is>k) continue;
		f[x]=y;
		st[++top]=q[i].id;
		ans+=q[i].is;
	} 
	
    for(i=1;i<=m;++i)	 
	if(q[i].is)q[i].w+=w;
	
	return ans;
} 

#define mid (l+r>>1)

int main()
{ 
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].w);q[i].id=i;
		q[i].is=(q[i].x==1)||(q[i].y==1);
	}
	if(check(U,1)<k||check(-U,1)>k||top<n-1) printf("-1\n");
	else
	{
		int l=-U,r=U;
		while(l+1!=r)
		if(check(mid,1)<k) l=mid;
		else r=mid;
		check(r,0);
		printf("%d\n",n-1);
		for(;top;--top) printf("%d ",st[top]);
    }
}