#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define L 1048576
#define real double
#define eps 1e-9
#define MAXN 1000005
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
void get(int &x)
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
void out(int x)
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
int n,i,j,a[MAXN],x[MAXN],y[MAXN];
int main()
{
	get(n);
	for(i=1;i<=n;i++)get(a[i]);
	for(x[0]=-1,i=1;i<=n;i++)x[i]=x[i-1]&~a[i];
	for(y[n+1]=-1,i=n;i;i--)y[i]=y[i+1]&~a[i];
	for(i=j=1;i<=n;i++)if((x[i-1]&y[i+1]&a[i])>(x[j-1]&y[j+1]&a[j]))j=i;
	out(a[j]);
	for(i=1;i<=n;i++)if(j!=i)
	{
		pc(' ');
		out(a[i]);
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}