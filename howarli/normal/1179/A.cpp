#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)>(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=300500,mo=1e9+7;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return n=n*w;
}
int n,m,ans;
int a[N],p[N];
int c[N];
LL b[N];
int Ans[N][2];
bool PX(int q,int w){return b[q]<b[w];}
int main()
{
	int q,w;
	read(n),read(m);
	fo(i,1,n)read(a[i]);
	fo(i,1,m)scanf("%I64d",&b[i]),p[i]=i;
	sort(p+1,p+1+m,PX);
	q=a[1],w=-1;
	int j=1;
	fo(i,1,n-1)
	{
		w=a[i+1];
		for(;j<=m&&b[p[j]]==i;++j)Ans[p[j]][0]=q,Ans[p[j]][1]=w;
		if(q<w)swap(q,w);
		c[i]=w;
	}
	--n;
	for(;j<=m;++j)Ans[p[j]][0]=q,Ans[p[j]][1]=c[(b[p[j]]-n-1)%n+1];
	fo(i,1,m)printf("%d %d\n",Ans[i][0],Ans[i][1]);
	return 0;
}