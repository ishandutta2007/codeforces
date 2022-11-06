#include<bits/stdc++.h>
#define rep(i,a,n) for(register int i=a;i<=n;++i)
#define per(i,a,n) for(register int i=a;i>=n;--i)
#define mem(a) memset(a,0,sizeof(a))
#define elif else if
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
inline int read()
{
	int f=1,x=0;
	char ch;
	do
	{
		ch=getchar();
		if(ch=='-')
		f=-1;
	}
	while(ch<'0'||ch>'9');
	do
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	while(ch>='0'&&ch<='9');
	return f*x;
}
int n,m,a[10001],b[10001],c[10001]={0},t=0;
bool check()
{
	rep(i,1,m)
	if(b[i]!=c[i])
	return false;
	return true;
}
int main()
{
	cin>>n>>m;
	rep(i,1,n)
	cin>>a[i];
	rep(i,1,m)
	{
		cin>>b[i]; 
		t+=b[i];
	}
	rep(i,1,t)
	++c[a[i]];
	if(check())
	{
		cout<<"YES";
		return 0;
	}
	rep(i,2,n-t+1)
	{
		--c[a[i-1]];
		++c[a[i+t-1]];
		if(check())
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}