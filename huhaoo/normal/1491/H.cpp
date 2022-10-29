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
const int N=200010,W=400;
int n,q,v[N],V[N],t[N],op[N];
void build(int k)
{
	int l=std::max(1,k*W),r=std::min(n,(k+1)*W-1); op[k]=0;
	fr(i,l,r)
		if(i%W<v[i]+V[k]) t[i]=std::max(1,i-v[i]-V[k]);
		else{ t[i]=t[i-v[i]-V[k]]; op[k]=1; }
}
int T(int u){ return u%W<v[u]+V[u/W]?std::max(1,u-v[u]-V[u/W]):t[u]; }
int main()
{
	n=read(); q=read(); v[0]=v[1]=2; t[0]=1;
	fr(i,2,n) v[i]=i-read();
	fr(i,0,n/W) build(i);
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int l=read(),r=read(),d=read();
			int L=l/W,R=r/W;
			if(L==R) fr(i,l,r){ if(v[i]<N) v[i]+=d; }
			else
			{
				fr(i,l,(L+1)*W-1) if(v[i]<N) v[i]+=d;
				fr(i,R*W,r) if(v[i]<N) v[i]+=d;
				fr(i,L+1,R-1) if(V[i]<N) V[i]+=d;
			}
			fr(i,L,R) if(::op[i]) build(i);
		}
		else
		{
			int u=read(),v=read();
			while(T(u)!=T(v))
			{
				if(u<v) std::swap(u,v);
//				printf("%d %d  %d %d\n",u,v,t[u],t[v]); fflush(stdout);
				u=T(u);
			}
			while(u!=v)
			{
				if(u<v) std::swap(u,v);
				u=std::max(u-::v[u]-::V[u/W],1);
			}
			printf("%d\n",u>0&&v>0?u:1);
		}
//		fr(i,1,n) printf("%d%c",t[i],i==n?'\n':' '); fflush(stdout);
//		fr(i,1,n) printf("%d%c",i-v[i]-V[i/W],i==n?'\n':' '); fflush(stdout);
	}
	return 0;
}