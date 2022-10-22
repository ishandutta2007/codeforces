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
int t,n,m,q,i,j,a[2005],s[2005],b[2005],c[2005],d[2005];
void fix(int x)
{
	d[++q]=x;
	s[a[x]]--;
	s[i]++;
	a[x]=i;
	for(i=0;i<n;i++)if(!s[i])break;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++)s[a[i]]++;
		for(m=n;m;m--)if(!s[m])break;
		for(i=j=0;i<=n;i++)if(i!=m)b[++j]=i;
		for(i=1;i<=n;i++)c[b[i]]=i;
		for(i=q=0;i<n;i++)if(!s[i])break;
		for(;;)
		{
			for(j=1;j<=n;j++)if(a[j]!=b[j])break;
			if(j>n)break;
			if(i==m)fix(j);
			else fix(c[i]);
		}
		printf("%d\n",q);
		for(i=1;i<=q;i++)printf("%d ",d[i]);
		putchar('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}