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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,Sum[N];
char s[N];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+((i&1)^(s[i]=='+')?-1:1);
		for(;m--;)
		{
			scanf("%d%d",&a,&b);
			if(Sum[b]-Sum[a-1]==0) {puts("0");continue;}
			puts((b-a)&1?"2":"1");
		}
	}
	return 0;
}