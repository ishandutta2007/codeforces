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
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n;
int main()
{
	for(scanf("%d",&T);T--;puts(""))
	{
		scanf("%d",&n);
		if(n==1) printf("9");
		else
		{
			printf("98");
			for(int i=3,c=9;i<=n;i++) putchar(c+48),c=c<9?c+1:0;
		}
	}
	return 0;
}