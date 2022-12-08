#include <iostream>
#include <cstdio>
#include <cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define abs(q) ((q)>0?(q):-(q))
using namespace std;
typedef double db;
const int N=505,M=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,m1;
int B[M*2][2],A[N],B0,B1[N];
int b1[N],zx[N];
db s[N][N],t[N][N],di[N][N];
void link(int q,int w)
{
	B1[q]++,B1[w]++;
	B[++B0][0]=A[q];A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w];A[w]=B0,B[B0][1]=q;
}
void chenans()
{
	fo(i,1,m)fo(j,1,m)t[i][j]=0;
	fo(k,1,m)fo(i,1,m)fo(j,1,m)t[i][j]+=s[i][k]*di[k][j];
	fo(i,1,m)fo(j,1,m)s[i][j]=t[i][j];
}
void chen()
{
	fo(i,1,m)fo(j,1,m)t[i][j]=0;
	fo(k,1,m)fo(i,1,m)fo(j,1,m)t[i][j]+=di[i][k]*di[k][j];
	fo(i,1,m)fo(j,1,m)di[i][j]=t[i][j];
}
db JC()
{
	while(m1)
	{
		if(m1&1)chenans();
		chen();m1>>=1;
	}
	db ans=0;
	fo(i,1,m)ans+=s[i][m];
	return ans;
}
db b[N][N],c[N][N];
int z[N];
void GS()
{
	fo(i,1,n)
	{
		b[i][i]=c[i][i]=1;
		efo(j,i)if(!zx[B[j][1]])b[i][B[j][1]]-=1.0/B1[B[j][1]];
	}
	fo(i,1,n)
	{
		int q=i;
		fo(j,i+1,n)if(abs(b[j][i])>abs(b[q][i]))q=j;
		if(q!=i)
		{
			fo(j,1,n)swap(b[i][j],b[q][j]),swap(c[i][j],c[q][j]);
		}
		fo(j,1,n)if(i!=j)
		{
			db t=b[j][i]/b[i][i];
			fo(k,1,n)b[j][k]-=t*b[i][k],c[j][k]-=t*c[i][k];
		}
	}
	fo(i,1,n)fo(j,1,n)c[i][j]/=b[i][i];
	efo(i,1)z[B[i][1]]++;
	fo(i,1,n)if(zx[i])
	{
		fo(j,1,n)
			s[zx[i]][zx[i]]+=c[i][j]*((db)z[j]/B1[1]);
	}
	fo(I,1,n)if(zx[I]&&B1[I])
	{ 
		fo(i,1,n)z[i]=0; 
		efo(i,I)z[B[i][1]]++;
		fo(i,1,n)if(zx[i])
		{
			fo(j,1,n)di[zx[I]][zx[i]]+=c[i][j]*((db)z[j]/B1[I]);
		}
	}
}
int main()
{
	int q,w;
	read(n),read(m),read(m1);
	m1-=2;if(m1<0){printf("0\n");return 0;}
	fo(i,1,n)if(read(q))b1[++b1[0]]=i,zx[i]=b1[0];
	fo(i,1,m)read(q),read(w),link(q,w); 
	GS();
	m=b1[0];
	printf("%.12lf\n",JC());
	return 0;
}