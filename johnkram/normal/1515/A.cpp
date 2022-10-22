#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L 1048576
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
int t,n,m,i,a[105],s[105];
int main()
{
	get(t);
	while(t--)
	{
		get(n);
		get(m);
		for(i=1;i<=n;i++)get(a[i]);
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		if(s[n]==m)
		{
			pc('N');
			pc('O');
			pc('\n');
			continue;
		}
		pc('Y');
		pc('E');
		pc('S');
		pc('\n');
		for(i=1;i<n;i++)if(s[i]==m)break;
		if(i<n)swap(a[i],a[i+1]);
		for(i=1;i<=n;i++)
		{
			out(a[i]);
			if(i==n)pc('\n');
			else pc(' ');
		}
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}