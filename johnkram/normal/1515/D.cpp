#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L 1048576
#define MAXN 200005
char _buf[L],*S,*T,c,_buf1[L],*S1=_buf1;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
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
void get(int &x)
{
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
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
inline int A(int x)
{
	return x<0?-x:x;
}
int t,n,l,r,i,j,ans,a[MAXN],s[MAXN];
int main()
{
	get(t);
	while(t--)
	{
		get(n);
		get(l);
		get(r);
		fill(s+1,s+n+1,0);
		for(i=1;i<=l;i++)
		{
			get(a[i]);
			s[a[i]]++;
		}
		for(;i<=n;i++)
		{
			get(a[i]);
			s[a[i]]--;
		}
		ans=0;
		for(i=1;i<=n;i++)if(s[i]>0)
		{
			j=max(0,min(l-r,s[i]))>>1;
			l-=j;
			r+=j;
			ans+=s[i];
		}
		else if(s[i]<0)
		{
			j=max(0,min(r-l,-s[i]))>>1;
			l+=j;
			r-=j;
			ans-=s[i];
		}
		out(ans+A(r-l)>>1);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}