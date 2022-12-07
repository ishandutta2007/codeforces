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
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,pre;
char s[N];
int main()
{
	for(scanf("%d",&T);T--;pre=0)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(pre!=2) putchar('1'),pre=2;
				else putchar('0'),pre=1;
			}
			else
			{
				if(pre!=1) putchar('1'),pre=1;
				else putchar('0'),pre=0;
			}
		}
		puts("");
	}
	return 0;
}