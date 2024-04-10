#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn];

inline bool cmp(int a,int b){return a>b;}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),F=0,nw=1,f=0; rep(i,1,n) a[i]=read(); sort(a+1,a+n+1,cmp);
		per(k,30,0)
		{
			int tmp=(1<<k),cnt=0;
			rep(i,1,n) if(a[i]&tmp) cnt++;
			if(cnt%4==1) {F=1; break;}
			else if(cnt%4==3)
			{
				if((n-cnt)%2==1) F=1;
				else F=-1; break;
			}
		}
		if(F==1) puts("WIN");
		else if(F==-1) puts("LOSE"); else puts("DRAW");
	}
	return 0;
}