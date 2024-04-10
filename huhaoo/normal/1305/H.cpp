#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=r*10+c-48; c=getchar(); }
	return r*t;
}
void nosol(){ printf("-1 -1\n"); exit(0); }
const int N=100010;
int n,m; i64 t,T;
int _l[N],_r[N],a[N]; i64 A[N];
int q,p[N],s[N],P[N],S[N],id[N];
int d[N];
int l,r;
int In(int x,int l,int r){ return std::min(std::max(x,l),r); }
bool check(int P,int v)
{
	memset(d,0,sizeof(d));
	p[0]=P; s[0]=v; t=T; fr(i,1,P) d[i]=v;
	fr(i,1,q) if(p[i]<=P&&v!=s[i]) return 0;
	if(p[1]<=P) p[0]=0;
	fr(i,1,q) d[p[i]]=s[i];
	fd(i,m,P+1) if(!d[i]) d[i]=d[i+1];
	fr(i,1,m) t-=d[i];
//	printf("%d %d  %I64d\n",P,v,t);
//	fr(i,1,m) printf("%d%c",d[i],i==m?'\n':' ');
	if(t<0) return 0;
	fd(i,q,0)
	{
		int L=std::max(P,p[i])+1,R=p[i+1]-1;
		if(L<=R&&t<=(i64)(R-L+1)*(s[i]-s[i+1]))
		{
			i64 k=t/(R-L+1);
			fr(j,L,R){ d[j]+=k; t-=k; }
			fr(j,L,L+t-1){ d[j]++; t--; }
			break;
		}
		else fr(j,L,R){ t-=s[i]-d[j]; d[j]=s[i]; }
	}
	if(t) return 0;
	fr(i,1,P) if(d[i]!=v) return 0;
	fr(i,1,m-1) if(d[i]<d[i+1]) return 0;
	fr(i,1,q) if(d[p[i]]!=s[i]) return 0;
	i64 S=0;
	fr(i,1,m){ S+=d[i]; /*printf("%I64d %I64d\n",S,A[i]);*/ if(S>A[i]) return 0; }
//	fr(i,1,m) printf("%d%c",d[i],i==m?'\n':' ');
	return 1;
}
int main()
{
	n=read(); m=read();
	fr(i,1,n){ _l[i]=read(); _r[i]=read(); }
	q=read();
	fr(i,1,q){ P[i]=read(); S[i]=read(); id[i]=i; }
	std::sort(id+1,id+q+1,[&](int a,int b){ return P[a]<P[b]; });
	fr(i,1,q){ p[i]=P[id[i]]; s[i]=S[id[i]]; /*printf("%d %d\n",p[i],s[i]);*/ }
	s[0]=n; p[q+1]=m+1; T=t=read(); l=1; r=m;
	while(l<=r)
	{
		int mid=(l+r)>>1; i64 _t=t;
		fr(i,1,n) _t-=(a[i]=In(mid-1,_l[i],_r[i]));
		fr(i,1,n) if(_t>0&&a[i]!=_r[i]&&a[i]==mid-1){ a[i]++; _t--; }
//		printf("%d %d  %I64d\n",l,r,_t);
		if(_t==0) break;
		else if(_t>0) l=mid+1;
		else r=mid-1;
		if(l>r) nosol();
	}
//	fr(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
	fr(i,1,n) if(a[i]) A[a[i]]++;
	fd(i,m,2) A[i-1]+=A[i];
	fr(i,1,m) A[i]+=A[i-1];
//	fr(i,1,m) printf("%I64d%c",A[i],i==m?'\n':' ');; putchar(10);
	if(!check(0,n)) nosol();
	int v=d[1],l=2,r=m+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid,v)) l=mid+1;
		else r=mid;
	}
	int P=l-1; l=v+1; r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(P,mid)) l=mid+1;
		else r=mid;
	}
	assert(check(P,l-1));
	printf("%d %d\n",P,l-1);
//	if(P==2&&l-1==54594) printf("%d %d %d\n",d[1],d[2],d[3]);
	return 0;
}