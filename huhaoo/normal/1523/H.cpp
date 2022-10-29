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
const int N=20010,L=14,K=30;
int n,q,a[N];
int f[L+1][K+1][N],m[K+1][L+1][N],b[N];
int tp=0;
inline int max(int a,int b){ return a>b?a:b; }
inline int Max(int *m,int d,int l,int r){ return max(m[l],m[r-d+1]); }
int g[K+1][N],G[K+1];
int ans[N],l[N],r[N],_k[N];
int main()
{
	clock_t st=clock();
//	printf("%.10lf\n",sizeof(m)/1024./1024.+sizeof(f)/1024./1024.);
	n=read(); q=read();
	fr(i,2,n) b[i]=b[i>>1]+1;
	fr(i,1,n)
	{
		if(tp==0) a[i]=read();
		else a[i]=rand()%n+1;
		fr(j,0,K) f[0][j][i]=std::min(n,i+a[i]+j);
	}
	fr(i,1,L)
	{
		fr(k,0,K)
		{
			fr(j,1,n) m[k][0][j]=f[i-1][k][j];
			fr(l,1,L) fr(j,1,n-(1<<l)+1)
				m[k][l][j]=max(m[k][l-1][j],m[k][l-1][j+(1<<(l-1))]);
		}
		fr(j,1,n) fr(k,0,K) fr(_k,0,k)
		{
			int _j=f[i-1][_k][j],B=b[_j-j+1];
			f[i][k][j]=max(f[i][k][j],Max(m[k-_k][B],1<<B,j,_j));
		}
	}
	fr(i,1,q)
	{
		if(tp==0){ l[i]=read(),r[i]=read(),_k[i]=read(),ans[i]=1; }
		else{ l[i]=rand()%n+1,r[i]=n,_k[i]=30,ans[i]=1; }
		fr(j,0,_k[i]) g[j][i]=f[0][j][l[i]];
		int flag=0;
		fr(j,0,_k[i]) if(g[j][i]>=r[i]) flag=1;
		if(!flag) ans[i]++;
	}
	fd(i,L,0)
	{
		fr(k,0,K)
		{
			fr(j,1,n) m[k][0][j]=f[i][k][j];
			fr(l,1,L) fr(j,1,n-(1<<l)+1)
				m[k][l][j]=max(m[k][l-1][j],m[k][l-1][j+(1<<(l-1))]);
		}
		fr(t,1,q)
		{
			fr(j,0,_k[t]) G[j]=0;
			fr(j,0,_k[t]) fr(k,0,j)
			{
				int _l=g[k][t],B=b[_l-l[t]+1];
				G[j]=max(G[j],Max(m[j-k][B],1<<B,l[t],_l));
			}
			int flag=1;
			fr(j,0,_k[t]) if(G[j]>=r[t]) flag=0;
			if(flag)
			{
				ans[t]+=(1<<i);
				fr(j,0,_k[t]) g[j][t]=G[j];
			}
		}
	}
	fr(i,1,q) printf("%d\n",l[i]==r[i]?0:ans[i]);
	clock_t ed=clock();// fprintf(stderr,"%d\n",ed-st);
	return 0;
}