#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int P=998244353,MAXN=100005,MAXM=20;
#define L 1048576
#define real double
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
int t,m,p,i,j,k,n,ans,a[35],f[35][35];
int main()
{
	get(t);
	while(t--)
	{
		get(m);
		m++;
		get(p);
		for(n=0;1<<n+1<m;n++)a[n]=1<<n;
		a[n]=m-(1<<n);
		for(i=0;i<=n;i++)
		for(i=ans=0;i<=n;i++)
		{
			a[i]%=p;
			f[1][i+1]=f[1][i]+a[i];
			if(f[1][i+1]>=p)f[1][i+1]-=p;
		}
		for(i=1;i<=n;i++)for(j=i;j<=n;j++)f[i+1][j+1]=(f[i+1][j]+(ll)f[i][j]*a[j])%p;
		for(i=1;i<=n+1;i++)
		{
			ans+=f[i][n+1];
			if(ans>=p)ans-=p;
		}
		out(ans);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}