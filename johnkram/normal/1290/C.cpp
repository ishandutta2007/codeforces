#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 10086001
#define L 1048576
#define real double
#define eps 1e-9
#define MAXN 300005
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
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
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
vector<int> a[MAXN];
int m,n,i,j,k,ans,f[MAXN],d[MAXN],s[MAXN][2],b[MAXN],e[MAXN];
int Get(int x)
{
	if(f[x]==x)return x;
	int r=Get(f[x]);
	b[x]^=b[f[x]];
	return f[x]=r;
}
int main()
{
	get(m);
	get(n);
	char c;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)
	{
		for(c=gc();c!='0'&&c!='1';c=gc());
		d[i]=c^'1';
	}
	for(i=1;i<=n;i++)
	{
		get(j);
		while(j--)
		{
			get(k);
			a[k].push_back(i);
		}
	}
	for(i=1;i<=n;i++)s[i][0]=1;
	for(i=1;i<=m;i++)
	{
		while(a[i].size()<2)a[i].push_back(0);
		j=Get(a[i][0]);
		k=Get(a[i][1]);
		if(!k)
		{
			swap(j,k);
			swap(a[i][0],a[i][1]);
		}
		if(j==k)
		{
			out(ans);
			pc('\n');
			continue;
		}
		ans-=s[j][1]+s[k][1];
		f[k]=j;
		if(e[k]^e[j]^b[a[i][0]]^b[a[i][1]]^d[i])swap(s[k][0],s[k][1]);
		b[k]=b[a[i][0]]^b[a[i][1]]^d[i];
		s[j][0]+=s[k][0];
		s[j][1]+=s[k][1];
		if(j&&s[j][0]<s[j][1])
		{
			swap(s[j][0],s[j][1]);
			e[j]=!e[j];
		}
		ans+=s[j][1];
		out(ans);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}