#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAXN=1000005,MAXM=30000000;
int P;
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
pair<int,int> p[1005];
int n,m,k,i,j,a[1005],u[1000005],v[1000005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++)a[p[i].second]=i;
	for(i=1;i<=n;i++)if(a[i]!=i)
	{
		for(j=i+1;j<=n;j++)if(a[i]>a[j])p[++k]=make_pair(a[j],j);
		sort(p+1,p+k+1);
		for(;k;k--)
		{
			u[++m]=i;
			v[m]=p[k].second;
			swap(a[i],a[p[k].second]);
		}
	}
	out(m);
	pc('\n');
	for(i=1;i<=m;i++)
	{
		out(u[i]);
		pc(' ');
		out(v[i]);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}