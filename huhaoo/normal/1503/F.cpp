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
#include<array>
#include<vector>
const int N=400010;
int n,e[N][2],p[N];
int a[N][2],id[N][2];
using std::abs;
std::vector<std::array<int,4> > op;
bool sgn(int a){ return a>0; }
int l[N],r[N];
void solve(int u)
{
	u=abs(u);
	if(p[u]) return ;
	if(abs(e[u][0])==u){ printf("NO\n"); exit(0); }
	if(abs(e[u][0])==abs(e[u][1]))
	{
		if(e[u][0]<0){ l[u]=-e[u][0]; r[-e[u][0]]=u; /*printf(" %d %d\n",-e[u][0],u);*/ }
		else{ r[u]=e[u][0]; l[e[u][0]]=u; /*printf(" %d %d",u,e[u][0]);*/ }
		if(e[u][0]!=e[u][1]){ printf("NO\n"); exit(0); }
		p[u]=p[abs(e[u][0])]=1;
	}
	if(sgn(e[u][0])==sgn(e[u][1])) return ;
	op.push_back({abs(e[u][0]),u,abs(e[u][1]),e[u][0]<0});
	p[u]=p[abs(e[u][1])]=1;
//	printf("+ %d %d\n",u,e[u][1]);
	int x=e[u][0],y=e[abs(e[u][1])][0];
	if(x==y){ printf("NO\n"); exit(0); }
	if(sgn(-x)==sgn(y))
	{
		e[abs(x)][0]=y; e[abs(y)][0]=x;
	}
	else
	{
		e[abs(x)][0]=y; e[abs(y)][0]=-x;
	}
//	printf(" %d %d  %d %d %d %d\n",x,y,e[abs(x)][0],e[abs(x)][1],e[abs(y)][0],e[abs(y)][1]);
	solve(x); solve(y); solve(e[abs(x)][1]); solve(e[abs(y)][1]);
}
void ins(int a,int b,int op)
{
	if(op==1)
	{
		r[b]=r[a]; l[r[a]]=b; l[b]=a; r[a]=b;
	}
	else
	{
		l[b]=l[a]; r[l[a]]=b; r[b]=a; l[a]=b;
	}
	
}
int main()
{
	n=read();
	fr(i,1,n+n){ a[i][0]=read(); a[i][1]=read(); }
	fr(i,0,1)
	{
		fr(j,1,n+n) if(a[j][i]<0) id[-a[j][i]][1]=j; else id[a[j][i]][0]=j;
		fr(j,1,n){ e[id[j][0]][i]=id[j][1]; e[id[j][1]][i]=-id[j][0]; }
	}
//	fr(i,1,n+n) printf("%d %d\n",e[i][0],e[i][1]);
	fr(i,1,n+n) solve(i);
	fr(i,1,n+n) if(!p[i]){ printf("NO\n"); return 0; }
	std::reverse(op.begin(),op.end());
	for(auto i:op){ /*printf("%d %d %d %d\n",i[0],i[1],i[2],i[3]);*/ ins(i[0],i[1],i[3]); ins(i[1],i[2],i[3]); }
	printf("YES\n");
	fr(i,1,n+n) if(!l[i])
	{
		int j=i;
		while(j)
		{
			printf("%d %d\n",a[j][0],a[j][1]); j=r[j];
		}
	}
	return 0;
}