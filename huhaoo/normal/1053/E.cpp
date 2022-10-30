/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Sat 03 Apr 2021 04:47:55 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
void nosol(int a=0){ printf("no\n"); if(a) printf("%d\n",a); exit(0); }
const int N=1<<21|10;
int n,a[N],p[N],q[N];
int v[N],vis[N];
int New(){ while(vis[v[0]]) v[0]++; vis[v[0]]=1; return v[0]; }
void solve(int l,int r)
{
	for(int i=l+1;i<r;i++) if(p[i]){ if(p[i]>r) nosol(); solve(i,p[i]); i=p[i]-1; }
	static int m,b[N],P[N],f[N],q[N],t0,t1;
	auto getf=[&](int u){ int F=u; while(f[F]!=F){ F=f[F]; } while(u!=F){ int k=f[u]; f[u]=F; u=k; } return F; };
	m=0; for(int i=l+1;i<r;i++) if(a[i]){ if(p[i]){ i=p[i]-1; continue; } m++; P[m]=i; b[m]=a[i]; } else{ m++; b[m]=0; P[m]=i; }
	fr(i,0,m) f[i]=i;
	t0=t1=0; b[0]=a[l];
	fr(i,1,m)
		if(b[i]) q[++t1]=i;
		else
		{
			if(t0+1<t1&&t0+1>=t1-t0)
			{
				int u=t0-(t1-t0-2);
				fr(i,0,t1-t0-2) f[getf(q[u+i])]=getf(q[t1-i]);
				t1=u; t0=u-1;
			}
			if(t1!=t0)
			{
				t1--; f[getf(i)]=getf(q[t1]);
			}
			else q[t1=++t0]=i;
		}
//	printf("%d %d   %d %d  %d\n",l,r,t0,t1,m);
	if(t0+1<t1)
	{
		if(t0+1>=t1-t0)
		{
			int u=t0-(t1-t0-2);
			fr(i,0,t1-t0-2) f[getf(q[u+i])]=getf(q[t1-i]);
			t1=u; t0=u-1;
		}
		else nosol();
	}
//	printf("%d %d\n",t0,t1);
	if(t0&&t0+1==t1)
	{
		f[getf(q[t0-1])]=getf(q[t1]); b[q[t0]]=New(); t1=--t0;
	}
	if(t1==t0) fr(i,1,t0/2) f[getf(q[i])]=getf(q[t0-i+1]);
	fr(i,0,m) if(b[i]) b[getf(i)]=b[i];
	fr(i,1,m)
	{
		if(!b[getf(i)]) b[getf(i)]=New();
		b[i]=b[getf(i)];
	}
	fr(i,1,m) a[P[i]]=b[i];
}
int main()
{
	n=read()*2-1; v[0]=1;
	fr(i,1,n) vis[a[i]=read()]=1;
	fr(i,2,n) if(a[i]&&a[i]==a[i-1]) nosol();
	fd(i,n,1) if(a[i]){ p[i]=q[a[i]]; q[a[i]]=i; }
	if(!a[1]&&!a[n])
	{
		static int m,b[N];
		m=0; for(int i=2;i<n;i++) if(a[i]){ if(p[i]){ i=p[i]-1; continue; } m++; b[m]=a[i]; } else{ m++; b[m]=0; }
		int t0=0,t1=0;
		fr(i,1,m)
		{
			if(b[i]) t1++;
			else
			{
				if(t0+1<t1&&t0+1>=t1-t0)
				{
					int u=t0-(t1-t0-2);
					t1=u; t0=u-1;
				}
				if(t1!=t0) t1--;
				else t1=++t0;
			}
			if(t1-t0-t0==2){ a[1]=b[i]; break; }
		}
		if(!a[1]) a[1]=New();
	}
	if(a[1]&&a[n]&&a[1]!=a[n]) nosol();
	if(a[1]) a[n]=a[1]; else a[1]=a[n];
	fr(i,1,n) p[i]=q[i]=0;
	fd(i,n,1) if(a[i]){ p[i]=q[a[i]]; q[a[i]]=i; }
	fr(i,1,n) if(p[i]&&(p[i]-i)%2!=0) nosol();
	solve(1,n);
	printf("yes\n");
	fr(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}