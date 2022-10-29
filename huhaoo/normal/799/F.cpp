#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=r*10+c-48; c=getchar(); }
	return r*t;
}
#include<vector>
#include<array>
#define op std::array<int,3>
#define info std::array<i64,2>
const int N=1<<20|10;
int n,m;
int l[N],r[N],p[N];
i64 ans;
std::vector<op> b[N];
i64 t[N]; info s[N];
info operator+(info a,info b){ return {a[0]+b[0],a[1]+b[1]}; }
info Q(int k){ return t[k]?info{0,0}:s[k]; }
void update(int k)
{
	int u=std::min(t[k<<1],t[k<<1|1]);
	t[k]+=u; t[k<<1]-=u; t[k<<1|1]-=u; s[k]=Q(k<<1)+Q(k<<1|1);
}
void pushdown(int k){ t[k<<1]+=t[k]; t[k<<1|1]+=t[k]; t[k]=0; }
void build(int k,int l,int r,int d)
{
	t[k]=0;
	if(l==r){ s[k]={1,l+l+d}; return ; }
	int mid=(l+r)>>1;
	build(k<<1,l,mid,d); build(k<<1|1,mid+1,r,d);
	update(k);
}
void modify(int k,int l,int r,int L,int R,int v)
{
	if(l>R||L>r) return ;
	if(L<=l&&r<=R){ t[k]+=v; return ; }
	int mid=(l+r)>>1; pushdown(k);
	modify(k<<1,l,mid,L,R,v); modify(k<<1|1,mid+1,r,L,R,v);
	update(k);
}
void add(int x,int y,int l,int r){ b[x].push_back({l,r,1}); b[y+1].push_back({l,r,-1}); }
int main()
{
	n=read(); m=read();
	fr(i,1,n){ l[i]=read(); r[i]=read(); p[l[i]]++; p[r[i]+1]--; }
	fr(i,1,m) p[i]+=p[i-1];
	fr(i,1,m) if(!p[i])
	{
		int j=i; while(j<=m&&!p[j]) j++;
		i64 s=j-i; fr(k,1,s) ans-=k*(s-k+1);
		i=j;
	}
	fr(x,0,1) fr(y,0,1)
	{
		int mx=(m+x)/2,my=(m+y)/2;
		if(!mx||!my) continue;
		build(1,1,my,-y);
		fr(i,1,mx) b[i].clear();
		fr(i,1,mx) add(i,i,1,i-1+(!x&&y));
		fr(i,1,n)
		{
			int lx=(l[i]+1+x)/2,rx=(r[i]+x)/2;
			int ly=(l[i]+1+y)/2,ry=(r[i]+y)/2;
			if((l[i]&1)!=y) add(1,lx-1,ly,ry);
			if(x!=y) add(lx,rx,ly,ry);
			if((r[i]&1)!=x) add(lx,rx,ry+1,my);
			if((l[i]&1)!=(r[i]&1)) add(1,lx-1,ry+1,my);
		}
		fr(i,1,mx)
		{
			for(auto j:b[i]) modify(1,1,my,j[0],j[1],j[2]);
			ans+=Q(1)[1]-(i+i-x-1)*Q(1)[0];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}