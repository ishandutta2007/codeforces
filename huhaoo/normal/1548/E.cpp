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
const int N=400010,M=200000;
int n,m,t;
int a[N],b[N];
int A[N],B[N];
std::vector<int> q[N],Q[N];
void solve(int *a,int n,int *A,int d)
{
	static int s[N],m[N],t; t=0;
	fr(i,1,n)
	{
		int M=a[i];
		while(t&&a[i]>a[s[t]]){ M=std::min(M,m[t]); t--; }
		if(t&&d==0) A[i]=std::min(A[i],::t-M);
		while(t&&a[i]==a[s[t]]){ M=std::min(M,m[t]); t--; }
		if(t&&d==1) A[i]=std::min(A[i],::t-M);
		t++; s[t]=i; m[t]=M;
	}
}
int s[N];
void Modify(int p,int v){ for(;p<=M;p+=p&(-p)) s[p]+=v; }
int query(int p){ int ans=0; p++; for(;p;p&=p-1) ans+=s[p]; return ans; }
void modify(int l,int r)
{
	l++; r++; Modify(l,1); Modify(r,-1);
}
int main()
{
	n=read(); m=read(); t=M+M-read();
	fr(i,1,n){ a[i]=M-read(); A[i]=M+1; }
	fr(i,1,m){ b[i]=M-read(); B[i]=M+1; }
#define rev(a,n) std::reverse(a+1,a+n+1)
	solve(a,n,A,1); rev(a,n); rev(A,n); solve(a,n,A,0); rev(a,n); rev(A,n);
	solve(b,m,B,1); rev(b,m); rev(B,m); solve(b,m,B,0); rev(b,m); rev(B,m);
//	fr(i,1,n) printf("%d %d\n",t-a[i]-M,A[i]-M);; putchar(10);
//	fr(i,1,m) printf("%d %d\n",t-b[i]-M,B[i]-M);
	fr(i,1,n)
	{
		int l=std::max(t-a[i],0),r=A[i];
		if(l<r){ q[l].push_back(a[i]); q[r].push_back(-a[i]); }
	}
	fr(i,1,m) Q[b[i]].push_back(i);
	i64 ans=0;
	fd(i,M+M,0)
	{
		for(auto j:Q[i])
		{
			int l=std::max(t-b[j],0),r=B[j];
			if(l<r){ /*printf("+ %d %d\n",l,r-1);*/ modify(l,r); }
		}
		for(auto j:q[i])
		{
			int x,y; if(j>0){ x=1; y=j; } else{ x=-1; y=-j; }
			ans+=x*query(y); //printf("Q %d %d\n",x,y);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}