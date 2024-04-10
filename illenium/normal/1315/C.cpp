#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int a[maxn],b[maxn],v[maxn],a1[maxn],a2[maxn],p[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),f=0,ff=0;
		for(int i=1;i<=n;i++) b[i]=read(),p[b[i]]=i;
		
		for(int i=1;i<=2*n;i++)
		{
			if(p[i]!=0)
			{
				a1[p[i]]=i;
			}
			else
			{
				f=0;
				for(int j=1;j<=n;j++) if(a1[j]!=0&&a2[j]==0) {f=1; a2[j]=i; break;}
				if(f==0) {ff=1; break;}
			}
		}
		if(ff==1) puts("-1");
		else {for(int i=1;i<=n;i++) printf("%d %d ",a1[i],a2[i]); puts("");}
		
		for(int i=1;i<=2*n;i++) p[i]=0,a1[i]=0,a2[i]=0;
	}
	return 0;
}