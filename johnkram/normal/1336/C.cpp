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
char s[3005],t[3005];
int n,m,i,j,k,ans,f[3005][3005];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=0;i<=n;i++)f[i][i]=1;
	for(k=0;k<n;k++)for(i=0;i+k<=n;i++)
	{
		j=i+k;
		if(i&&(i>m||t[i]==s[k+1]))
		{
			f[i-1][j]+=f[i][j];
			if(f[i-1][j]>=P)f[i-1][j]-=P;
		}
		if(j<n&&(j+1>m||t[j+1]==s[k+1]))
		{
			f[i][j+1]+=f[i][j];
			if(f[i][j+1]>=P)f[i][j+1]-=P;
		}
	}
	for(i=m;i<=n;i++)
	{
		ans+=f[0][i];
		if(ans>=P)ans-=P;
	}
	cout<<ans<<endl;
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}