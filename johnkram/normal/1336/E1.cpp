#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int P=998244353,MAXN=1048576,MAXM=20000000;
#define L 1048576
#define real long double
#define eps 1e-9
char _buf[L],*S,*T,_buf1[L],*S1=_buf1;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
template<class T> void get(T &x)
{
	char c;
	for(c=gc();(c<'0'||c>'9')&&c!='-';c=gc());
	bool b=0;
	if(c=='-')
	{
		b=1;
		c=gc();
	}
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
	if(b)x=-x;
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void out(ll x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int A(int x)
{
	return x<0?-x:x;
}
int n,m,N,M,i,j,k,ans[64],o[262144],d[64][65536];
ll f[4096],g[4096];
ll x;
inline int ask(ll x)
{
	return o[x>>36]+o[x>>18&262143]+o[x&262143];
}
struct node
{
	int m,N;
	ll a[64];
	bool fix(ll x)
	{
		int i,j;
		for(i=m-1;~i;i--)if(x>>i&1)if(a[i])x^=a[i];
		else
		{
			N++;
			a[i]=x;
			return 1;
		}
		return 0;
	}
	void init()
	{
		int i,j,k;
		for(i=m-1;~i;i--)for(j=i+1;j<m;j++)if(a[j]>>i&1)a[j]^=a[i];
		for(i=m-1;i>=m-N;i--)
		{
			for(j=i;~j;j--)if(a[j])break;
			if(j!=i)
			{
				swap(a[j],a[i]);
				for(k=0;k<m;k++)if((a[k]>>i&1)^(a[k]>>j&1))a[k]^=1LL<<i^1LL<<j;
			}
		}
	}
}a0;
int main()
{
	get(n);
	get(m);
	for(i=1;i<262144;i++)o[i]=o[i>>1]+(i&1);
	a0.m=m;
	while(n--)
	{
		get(x);
		if(!a0.fix(x))M++;
	}
	a0.init();
	if(m-a0.N<=16)
	{
		d[0][0]=1;
		for(i=m-1;i>=m-a0.N;i--)
		{
			for(j=m-i-1;~j;j--)for(k=0;k<1<<m-a0.N;k++)if(d[j][k])
			{
				d[j+1][k^(a0.a[i]&((1LL<<m-a0.N)-1))]+=d[j][k];
				if(d[j+1][k^(a0.a[i]&((1LL<<m-a0.N)-1))]>=P)d[j+1][k^(a0.a[i]&((1LL<<m-a0.N)-1))]-=P;
			}
		}
		for(i=0;i<=a0.N;i++)for(j=0;j<1<<m-a0.N;j++)if(d[i][j])
		{
			k=i+ask(j);
			ans[k]+=d[i][j];
			if(ans[k]>=P)ans[k]-=P;
		}
		for(i=0,j=Pow(2,M);i<=m;i++)cout<<(ll)ans[i]*j%P<<' ';
		return 0;
	}
	if(a0.N<=24)
	{
		N=a0.N>>1;
		for(i=0;i<N;i++)for(j=0;j<1<<i;j++)f[1<<i|j]=f[j]^(a0.a[m-i-1]&((1LL<<m-a0.N)-1));
		for(i=0;i<a0.N-N;i++)for(j=0;j<1<<i;j++)g[1<<i|j]=g[j]^(a0.a[m-N-i-1]&((1LL<<m-a0.N)-1));
		for(i=0;i<1<<a0.N;i++)ans[ask(i)+ask(f[i&((1<<N)-1)]^g[i>>N])]++;
		for(i=0,j=Pow(2,M);i<=m;i++)cout<<(ll)ans[i]*j%P<<' ';
		return 0;
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}