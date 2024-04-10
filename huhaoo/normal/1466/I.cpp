#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<assert.h>
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
const int N=1210;
#ifdef huhao
int ty=1;
#elif _r
int ty=2;
#else
int ty=0;
#endif
int n,m,Val[N][N];
int query(int p,int *v)
{
	if(v[m]) return 1;
	if(ty<=1){ printf("%d ",p); fd(i,m-1,0) putchar(v[i]+48);; putchar(10); fflush(stdout); }
	if(!ty){ char s[5]; scanf("%s",s); return *s=='y'; }
	fd(i,m-1,0) if(Val[p][i]!=v[i]) return Val[p][i]>v[i];
	return 0;
}
int v[N];
int query(int p,int d)
{
//	printf("%d %d\n",p,d);
	assert(p>=0&&d>=0);
	if(d>=m) return 1;
//	assert(!v[d]);
	static int V[N];
	fr(i,0,d-1){ V[i]=v[i]; v[i]=1; } int ans=!query(p,v); fr(i,0,d-1) v[i]=V[i];
	return ans;
}
int q[N];
void Assert(int op)
{
	if(op) return ;
	fr(i,1,n){ fd(j,m-1,0) putchar(Val[i][j]+48);; putchar(10); } putchar(10);
	assert(0);
}
void print()
{
	if(ty==2)
	{
		int flag=0;
		fr(i,1,n)
		{
			fd(j,m-1,0)
			{
				if(Val[i][j]!=v[j]){ Assert(Val[i][j]<v[j]); break; }
				if(!j) flag=1;
			}
		}
		Assert(flag); exit(0);
	}
//	fd(i,m-1,0) fprintf(stderr,"%d%c",v[i],i==0?'\n':' ');
	printf("0 "); fd(i,m-1,0) putchar(v[i]+48);; putchar(10); fflush(stdout); exit(0);
}
void solve(int x,int y,int z)
{
//	fr(i,1,n) putchar(q[i]+48);; printf(" %d %d %d\n",x,y,z);
	if(x<0)
	{
		assert(!z);
		fr(I,1,y==n+1?n:n-1)
		{
			int i=(y-I); if(i<=0) i+=n;
			if(q[i]&&!query(i,z))
			{
				fr(J,1,I-1)
				{
					int j=(y-J); if(j<=0) j+=n;
					if(q[j]) q[j]=0;
				}
				if(q[y]) q[y]=0;
				return ;
			}
		}
		print();
	}
	int p=0;
	fr(I,1,y==n+1?n:n-1)
	{
		int i=(y-I); if(i<=0) i+=n;
		if(!q[i]) continue;
//		printf("%d %d %d\n",i,x,z);
		if(query(i,x))
		{
			solve(x-1,i,x);
			v[x]=1; fr(j,0,x-1) v[j]=0; if(x) x--; else p=1;
		}
		else
		{
			if(!query(i,z))
			{
				fr(J,1,I-1)
				{
					int j=(y-J); if(j<=0) j+=n;
					if(q[j]) q[j]=0;

				}
				if(q[y]) q[y]=0;
				return ;
			}
			v[x]=1; fr(j,0,x-1) v[j]=0;
			if(x) x--; else p=1;
		}
	}
	if(x||!p) solve(x,n+1,m);
	print();
}
#include<random>
int main()
{
	if(ty!=2)
	{
		n=read(); m=read();
	}
	else n=m=3;
	if(ty)
	{
		if(ty==1) fr(i,1,n) fd(j,m-1,0) scanf("%1d",&Val[i][j]);
		else
		{
			std::mt19937 _rand((unsigned long long)new char);
			fr(i,1,n) fr(j,0,m-1) Val[i][j]=_rand()&1;
		}
	}
	fr(i,1,n) q[i]=1;
	solve(m-1,n+1,m);
	print();
	return 0;
}