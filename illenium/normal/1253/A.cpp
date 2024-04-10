#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

int a[maxn],b[maxn],c[maxn],d[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),fl=0,f2=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) b[i]=read();
		for(int i=1;i<=n;i++) c[i]=b[i]-a[i];
		for(int i=1;i<=n;i++) if(c[i]<0) fl=1;
		if(fl) {puts("NO"); continue;}
		int cnt=0,l=0,r=0;
		//for(int i=1;i<=n;i++) cout<<c[i]<<" "; cout<<endl;
		for(int i=1;i<=n;i++) if(c[i]!=0) {l=i; break;}
		for(int i=n;i>=1;i--) if(c[i]!=0) {r=i; break;}
		for(int i=l+1;i<=r;i++) if(c[i]!=c[i-1]) f2=1;
		if(f2==1) puts("NO");
		else puts("YES");
	}
	return 0; 
}