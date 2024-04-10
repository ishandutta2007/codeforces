#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define PR(...) printf(__VA_ARGS__)
#define EPR(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long LL;
const int N=100500,M=280;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N];
int nx[N][30];
int f[M][M][M];
int lg[10];
int b[4][M];
int MIN(int &q,int w){return q=min(q,w);}
int main()
{
	int q,w;
	read(n),read(m);
	char ch=' ';
	for(;ch<'a'||ch>'z';ch=getchar());
	fo(i,1,n)a[i]=ch-'a'+1,ch=getchar();
	fo(i,1,26)nx[n+1][i]=n+1;
	fod(i,n,0)
	{
		fo(j,1,26)nx[i][j]=nx[i+1][j];
		nx[i][a[i]]=i;
	}
	fo(i,0,250)fo(j,0,250)fo(k,0,250)f[i][j][k]=n+1;
	f[0][0][0]=0;
	fo(I,1,m)
	{
		for(ch=' ';ch!='-'&&ch!='+';ch=getchar());
		read(q);
		if(ch=='-')
		{
			///////////////////////////
			if(q==1)
			{
				fo(i,0,lg[2])fo(j,0,lg[3])f[lg[1]][i][j]=n+1;
			}else if(q==2)
			{
				fo(i,0,lg[1])fo(j,0,lg[3])f[i][lg[2]][j]=n+1;
			}else
			{
				fo(i,0,lg[1])fo(j,0,lg[2])f[i][j][lg[3]]=n+1;
			}
			--lg[q];
		}else
		{
			for(ch=' ';ch<'a'||ch>'z';ch=getchar());
			int nw=ch-'a'+1;
			if(q==1)
			{
				fo(i,0,lg[2])fo(j,0,lg[3])if(f[lg[1]][i][j]<=n)
				{
					MIN(f[lg[1]+1][i][j],nx[f[lg[1]][i][j]+1][nw]);
				}
				++lg[1];
				b[1][lg[1]]=nw;
				fo(i,0,lg[2])fo(j,0,lg[3])if(f[lg[1]][i][j]<=n)
				{
					if(i<lg[2])MIN(f[lg[1]][i+1][j],nx[f[lg[1]][i][j]+1][b[2][i+1]]);
					if(j<lg[3])MIN(f[lg[1]][i][j+1],nx[f[lg[1]][i][j]+1][b[3][j+1]]);
				}
			}else if(q==2)
			{
				fo(i,0,lg[1])fo(j,0,lg[3])if(f[i][lg[2]][j]<=n)
				{
					MIN(f[i][lg[2]+1][j],nx[f[i][lg[2]][j]+1][nw]);
				}
				++lg[2];
				b[2][lg[2]]=nw;
				fo(i,0,lg[1])fo(j,0,lg[3])if(f[i][lg[2]][j]<=n)
				{
					if(i<lg[1])MIN(f[i+1][lg[2]][j],nx[f[i][lg[2]][j]+1][b[1][i+1]]);
					if(j<lg[3])MIN(f[i][lg[2]][j+1],nx[f[i][lg[2]][j]+1][b[3][j+1]]);
				}
			}else
			{
				fo(i,0,lg[1])fo(j,0,lg[2])if(f[i][j][lg[3]]<=n)
				{
					MIN(f[i][j][lg[3]+1],nx[f[i][j][lg[3]]+1][nw]);
				}
				++lg[3];
				b[3][lg[3]]=nw;
				fo(i,0,lg[1])fo(j,0,lg[2])if(f[i][j][lg[3]]<=n)
				{
					if(i<lg[1])MIN(f[i+1][j][lg[3]],nx[f[i][j][lg[3]]+1][b[1][i+1]]);
					if(j<lg[2])MIN(f[i][j+1][lg[3]],nx[f[i][j][lg[3]]+1][b[2][j+1]]);
				}
			}
			
		}
//		EPR("%d\n",f[lg[1]][lg[2]][lg[3]]);
		if(f[lg[1]][lg[2]][lg[3]]<=n)PR("YES\n");
		else PR("NO\n");
	}
	
	return 0;
}