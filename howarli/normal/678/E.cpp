#include<iostream>
#include<cstdio> 
#include<cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef double db;
const int N=25;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int n;
int b[N],b1[N];
db a[N][N],f[N][(1<<19)+10],ans;
int er[N];
void ss(int q,int w,int e)
{
	if(q>n)
	{
		fo(i,1,n)if((er[i]&e))
			fo(j,1,n)if((er[j]&(e-er[i])))
				f[i][e]=max(f[i][e],f[i][e-er[j]]*a[i][j]+f[j][e-er[i]]*a[j][i]);
		return;
	}
	if(q+w<=n)ss(q+1,w,e);
	if(w)ss(q+1,w-1,e+er[q]);
}
int main()
{
//	freopen("!.in","r",stdin);
	er[1]=1;fo(i,2,N-1)er[i]=er[i-1]<<1;
	int q,w;
	read(n);
	fo(i,1,n)fo(j,1,n)scanf("%lf",&a[i][j]);
	f[1][1]=1;
	fo(i,2,n)ss(1,i,0);
	ans=0;
	fo(i,1,n)ans=max(ans,f[i][er[n+1]-1]);
	printf("%.7lf\n",ans);
	return 0;
}