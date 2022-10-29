#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
#define info std::array<i64,3>
const int N=1<<20|10;
int n,q;
i64 a[N];
info t[N];
info operator+(info a,info b)
{
	return info{a[0]+b[0],std::min(a[1],b[1]+a[0]),std::max(a[2],b[2]+a[0])};
}
void build(int k,int l,int r)
{
	if(l==r){ t[k]={a[l],std::min(a[l],0ll),std::max(a[l],0ll)}; return ; }
	int mid=(l+r)>>1; build(k<<1,l,mid); build(k<<1|1,mid+1,r); t[k]=t[k<<1]+t[k<<1|1];
}
info query(int k,int l,int r,int L,int R)
{
	if(l>R||L>r) return info{0ll,0ll,0ll};
	if(L<=l&&r<=R) return t[k];
	int mid=(l+r)>>1;
	return query(k<<1,l,mid,L,R)+query(k<<1|1,mid+1,r,L,R);
}
int main()
{
	n=read(); q=read();
	fr(i,1,n) a[i]-=read();
	fr(i,1,n) a[i]+=read();
	build(1,1,n);
	while(q--)
	{
		int l=read(),r=read();
		info ans=query(1,1,n,l,r);
		printf("%I64d\n",ans[1]<0||ans[0]?-1:ans[2]);
	}
	return 0;
}