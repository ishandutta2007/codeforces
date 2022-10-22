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
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
bool b;
int t,n,m,i,j,k,l,a[305][305];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",a[i]+j);
		for(i=b=1;i<=n;i++)for(j=1;j<=m;j++)
		{
			for(k=l=0;k<4;k++)if(i+dx[k]>0&&i+dx[k]<=n&&j+dy[k]>0&&j+dy[k]<=m)l++;
			if(a[i][j]>l)b=0;
			else a[i][j]=l;
		}
		if(b)
		{
			puts("YES");
			for(i=1;i<=n;i++,putchar('\n'))for(j=1;j<=m;j++)printf("%d ",a[i][j]);
		}
		else puts("NO");
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}