#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int v[maxn],c[maxn],a,b,k;

inline int wk(int a,int b)
{
	if(a==0) return 0;
	if(a%b==0) return a/b;
	return a/b+1;
}

int main()
{
	int n=read(),a=read(),b=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		v[i]=read();
		v[i]%=(a+b); if(v[i]==0) v[i]+=(a+b); v[i]-=a;
		if(v[i]<=0) continue;
		c[i]=wk(v[i],a); //cout<<c[i]<<endl;
	}
	sort(c+1,c+n+1);
	ll pre=0;
	for(int i=1;i<=n;i++)
	{
		pre+=c[i];
		if(pre>k) {cout<<i-1<<endl; return 0;}
	}
	cout<<n<<endl;
	return 0;
}