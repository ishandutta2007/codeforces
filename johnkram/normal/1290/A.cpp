#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 10086001
#define L 1048576
#define real double
#define eps 1e-9
#define MAXN 1000005
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
int t,n,m,k,i,j,a[4005],b[4005],q[4005],he,ta,ans;
int main()
{
	get(t);
	while(t--)
	{
		get(n);
		get(m);
		get(k);
		for(i=1;i<=n;i++)get(a[i]);
		for(i=1;i<=m;i++)b[i]=max(a[i],a[i+n-m]);
		k=max(1,m-k);
		he=ta=ans=0;
		for(i=1;i<=m;i++)
		{
			while(he!=ta&&b[q[ta-1]]>=b[i])ta--;
			q[ta++]=i;
			if(q[he]+k==i)he++;
			if(i>=k)ans=max(ans,b[q[he]]);
		}
		out(ans);
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}