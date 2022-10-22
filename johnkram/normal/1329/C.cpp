#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int P=998244353,MAXN=2100000,MAXM=20;
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
ll A2;
int t,n,m,N,M,A1,i,a[MAXN],s[MAXN],ans[MAXN];
int ask(int x)
{
	if(!a[x])return N;
	int t=s[x];
	if(a[x<<1]>a[x<<1|1])t=min(s[x],ask(x<<1));
	else t=min(s[x],ask(x<<1|1));
	return t;
}
void del(int x)
{
	if(!s[x])
	{
		a[x]=0;
		return;
	}
	s[x]--;
	if(a[x<<1]>a[x<<1|1])
	{
		a[x]^=a[x<<1]^=a[x]^=a[x<<1];
		del(x<<1);
	}
	else
	{
		a[x]^=a[x<<1|1]^=a[x]^=a[x<<1|1];
		del(x<<1|1);
	}
}
void work(int x)
{
	if(!s[x])return;
	while(ask(x))
	{
		ans[++A1]=x;
		del(x);
	}
	work(x<<1);
	work(x<<1|1);
}
int main()
{
	get(t);
	while(t--)
	{
		get(n);
		get(m);
		N=1<<n;
		M=1<<m;
		fill(a+N,a+(N<<1),0);
		fill(s+N,s+(N<<1),0);
		for(i=1;i<N;i++)get(a[i]);
		for(i=N-1;i>=M;i--)s[i]=s[i<<1]+s[i<<1|1]+1;
		for(i;i;i--)s[i]=s[i<<1]+s[i<<1|1];
		A1=A2=0;
		work(1);
		for(i=1;i<M;i++)A2+=a[i];
		out(A2);
		pc('\n');
		for(i=1;i<=A1;i++)
		{
			out(ans[i]);
			pc(' ');
		}
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}