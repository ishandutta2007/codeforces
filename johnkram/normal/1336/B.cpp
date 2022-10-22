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
ll ans;
int t,i,j,k,l,n[3],p[3],a[3][MAXN];
inline ll dis(int x,int y,int z)
{
	return (ll)(x-y)*(x-y)+(ll)(y-z)*(y-z)+(ll)(z-x)*(z-x);
}
int main()
{
	get(t);
	while(t--)
	{
		ans=1LL<<62;
		for(i=0;i<3;i++)get(n[i]);
		for(i=0;i<3;i++)for(j=1;j<=n[i];j++)get(a[i][j]);
		for(i=0;i<3;i++)sort(a[i]+1,a[i]+n[i]+1);
		for(i=0;i<3;i++)a[i][n[i]+1]=1<<30;
		for(i=0;i<3;i++)p[i]=i;
		do
		{
			for(i=1,j=k=0;i<=n[p[0]]&&j<=n[p[1]]&&k<=n[p[2]];i++)
			{
				for(;j<=n[p[1]]&&a[p[1]][j+1]<=a[p[0]][i];j++);
				for(;k<=n[p[2]]&&a[p[2]][k]<a[p[0]][i];k++);
				if(j&&k&&i<=n[p[0]]&&j<=n[p[1]]&&k<=n[p[2]])ans=min(ans,dis(a[p[0]][i],a[p[1]][j],a[p[2]][k]));
			}
		}while(next_permutation(p,p+3));
		out(ans);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}