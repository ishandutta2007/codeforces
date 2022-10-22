#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int P=998244353,MAXN=1000005;
#define L 1048576
#define real double
#define eps 1e-9
#define MAXM 1000005
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
int n,m,l,i,j,a1,a2,h[MAXN],ne[MAXN],p[MAXN],h1[MAXN],n1[MAXN],p1[MAXN],q[MAXN],a[MAXN],he,ta,d[MAXN],s[MAXN];
int main()
{
	get(n);
	get(m);
	for(i=1;i<=m;i++)
	{
		get(p1[i]);
		get(p[i]);
		ne[i]=h[p1[i]];
		h[p1[i]]=i;
		n1[i]=h1[p[i]];
		h1[p[i]]=i;
	}
	get(l);
	for(i=1;i<=l;i++)get(a[i]);
	memset(d,-1,sizeof(d));
	d[q[ta++]=a[l]]=0;
	while(he!=ta)for(j=h1[i=q[he++]];j;j=n1[j])if(!~d[p1[j]])d[q[ta++]=p1[j]]=d[i]+1;
	for(i=1;i<=n;i++)for(j=h[i];j;j=ne[j])s[i]+=d[i]==d[p[j]]+1;
	for(i=1;i<l;i++)if(d[a[i]]!=d[a[i+1]]+1)a1++;
	else a2+=s[a[i]]>1;
	cout<<a1<<' '<<a1+a2<<endl;
	return 0;
}