#include<bits/stdc++.h>
using namespace std;
namespace _io
{
	int const rlen=1<<22|1;
	inline char gc()
	{
	    static char buf[rlen],*p1,*p2;
	    (p1==p2)&&(p2=(p1=buf)+fread(buf,1,rlen,stdin));
	    return p1==p2?EOF:*p1++;
	} template<typename T>inline T In()
	{
		T v=0; char c=gc(); bool flag=false;
		while(c<'0'||c>'9') flag|=(c=='-'),c=gc();
		while('0'<=c&&c<='9') v=(v<<1)+(v<<3)+(c^48),c=gc();
		return flag?-v:v;
	} inline int rd() {return In<int>();}
	  inline long long rdl() {return In<long long>();}
	template<typename T>inline void wt(T i)
	{
		int fi[20],p=1;
		if(i<0) putchar('-'),i=-i; if(!i) fi[p++]=0;
		else while(i) fi[p++]=i%10,i/=10;
		for(int j=p-1;j;j--) putchar(fi[j]+48);
	}
}using namespace _io;
int const maxn=4e3+5;
int n,k;
int sum[maxn][maxn];
inline int w(int i,int j)
{return sum[j][j]-sum[i-1][j]-sum[j][i-1]+sum[i-1][i-1];}

int f[maxn][maxn];
void solve(int d,int l,int r,int optl,int optr)
{
	int mid=l+r>>1,opt=0;
	for(int i=optl;i<=min(mid,optr);i++)
		if(f[d-1][i-1]+w(i,mid) < f[d][mid])
			f[d][mid] = f[d-1][i-1]+w(i,mid),
			opt=i;
	if(l<r) solve(d,l,mid,optl,opt),solve(d,mid+1,r,opt,optr);
}
int main()
{
	#ifdef Zplus17
	freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+rd();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=k;i++)
		solve(i,1,n,1,n);
	cout<<f[k][n]/2;
	return 0;
}