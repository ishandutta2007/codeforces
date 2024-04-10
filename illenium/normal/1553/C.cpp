#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
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

char ch[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",ch);
		int p1=0,p2=0,tmax=0,tmin=0,res1=5,res2=5,ans=10;
		rep(s,0,1023)
		{
			bool F=1;
			rep(i,0,9)
			{
				if(ch[i]=='0'&&(s>>i&1)) F=0;
				if(ch[i]=='1'&&!(s>>i&1)) F=0;
			}
			if(!F) continue;
			int p1=0,p2=0,resx=5,resy=5;
			rep(i,0,9)
			{
				if(i%2==0)
				{
					resx--;
					if(s>>i&1) p1++;
				}
				else
				{
					resy--;
					if(s>>i&1) p2++;
				}
				if(p1+resx<p2||p2+resy<p1) {ans=min(ans,i+1); break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}