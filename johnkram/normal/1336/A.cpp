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
struct node
{
	int i,a;
	bool operator<(const node& y)const
	{
		return a<y.a;
	}
}t;
priority_queue<node> H;
ll ans;
int n,q,m,i,j,k,h[MAXN],ne[MAXN],p[MAXN],s[MAXN],d[MAXN],f[MAXN],a[MAXN];
void dfs(int x)
{
	s[x]=1;
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		d[p[i]]=d[x]+1;
		dfs(p[i]);
		s[x]+=s[p[i]];
	}
}
int main()
{
	get(n);
	get(q);
	for(i=1;i<n;i++)
	{
		get(j);
		get(k);
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	dfs(1);
	for(i=1;i<=n;i++)a[i]=s[i]-d[i]-1;
	t.i=1;
	t.a=a[1];
	H.push(t);
	for(q=n-q;q--;)
	{
		t=H.top();
		H.pop();
		ans+=t.a;
		for(i=t.i,j=h[i];j;j=ne[j])if(p[j]!=f[i])
		{
			t.i=p[j];
			t.a=a[p[j]];
			H.push(t);
		}
	}
	cout<<ans<<endl;
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}