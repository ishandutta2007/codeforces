#include <cstdio>
#include <algorithm>
#include <cmath>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define pre(q) ((q)*(q))
using namespace std;
typedef double db;
const int N=1500,INF=2147483640;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans,r;
db a[N][2];
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(r);
	fo(i,1,n)
	{
		read(q);
		a[i][0]=q;a[i][1]=r;
		fo(j,1,i-1)
		{
			db t=pre(2.0*r)-pre(a[i][0]-a[j][0]);
			if(t>=0)
			{
				t=sqrt(t);
				a[i][1]=max(a[i][1],t+a[j][1]);
			}
		}
		printf("%.10lf ",a[i][1]);
	}
	printf("\n");
	return 0;
}