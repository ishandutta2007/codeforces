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

int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read();
		int a1=0,a2=0,a3=0,ans=inf;
		for(int i=1;i<=10000;i++)
		{
			for(int j=1;i*j<=100000;j++)
			{
				int tmp=0,p2=c; tmp+=abs(a-i),tmp+=abs(b-(i*j));
				int res=c%(i*j); p2-=res;
				if(res>i*j-res||p2==0) p2+=i*j,res=i*j-res; tmp+=res;
				if(tmp<ans) ans=tmp,a1=i,a2=i*j,a3=p2;
			}
		}
		printf("%d\n%d %d %d\n",ans,a1,a2,a3);
	}
	return 0;
}