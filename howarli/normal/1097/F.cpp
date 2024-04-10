#include <cstdio>
#include <algorithm>
#include <bitset>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=100500,M=7005;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
bitset<M>ad[N];
bitset<M>SU[M];
bitset<M>Mu[M];
bool prz[N];
int mu[N],pr[N];
void Pre(int n)
{
	mu[1]=1;
	fo(i,2,n)
	{
		if(!prz[i])pr[++pr[0]]=i,mu[i]=-1;
		fo(j,1,pr[0])
		{
			int t=i*pr[j];
			if(t>n)break;
			prz[t]=1;
			if(i%pr[j]==0){mu[t]=0;break;}
			mu[t]=-mu[i];
		}
	}
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w,e;
	read(n),read(m);
	w=7001;
	Pre(w);
	fo(i,1,w)
	{
		fo(j,1,w)
		{
			if(i*j>w)break;
			if(mu[j])Mu[i][i*j]=1;
			SU[i*j][i]=1;
		}
	}
	// fo(i,1,10)
	// {
	// 	fo(j,1,10)printf("%d",int(SU[i][j]));
	// 	printf("\n");
	// }
	fo(I,1,m)
	{
		read(e),read(q),read(w);
		// fo(i,1,n)
		// {
		// 	// fo(j,1,8)printf("%d",int(a[i][j]));
		// 	// printf("   ");
		// 	fo(j,1,8)printf("%d",int(ad[i][j]));
		// 	printf("\n");
		// }
		// printf("-------------------------------\n");
		if(e==1)
		{
			// a[q]=0;a[q][w]=1;
			ad[q]=SU[w];
		}else if(e==2)
		{
			read(e);
			// a[q]=a[w]^a[e];
			ad[q]=ad[w]^ad[e];
		}else if(e==3)
		{
			read(e);
			ad[q]=ad[w]&ad[e];
			// ad[q]=ad[w]|ad[e];
		}else 
		{
			e=(ad[q]&Mu[w]).count();
			if(e&1)printf("1");
			else printf("0");
		}
	}
	printf("\n");
	return 0;
}