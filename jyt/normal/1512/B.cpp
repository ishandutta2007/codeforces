#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 405
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,ax,ay,bx,by;
char s[N][N];
int main()
{
	for(scanf("%d",&T);T--;ax=ay=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(s[i][j]=='*')
					if(ax) bx=i,by=j;
					else ax=i,ay=j;
		// dbg1(ax),dbg2(ay);
		// dbg1(bx),dbg2(by);
		if(ax!=bx&&ay!=by) s[ax][by]=s[bx][ay]='*';
		else
		{
			if(ax==bx)
			{
				if(ax>1) s[ax-1][ay]=s[ax-1][by]='*';
				else s[ax+1][ay]=s[ax+1][by]='*';
			}
			else
			{
				if(ay>1) s[ax][ay-1]=s[bx][ay-1]='*';
				else s[ax][ay+1]=s[bx][by+1]='*';
			}
		}
		for(int i=1;i<=n;i++) printf("%s\n",s[i]+1);
	}
	return 0;
}