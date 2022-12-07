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
int T,n;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		if(n==1) {puts("a");continue;}
		for(int i=1;i<=n>>1;i++) putchar('a');
		putchar('b');
		for(int i=1;i<n>>1;i++) putchar('a');
		if(n&1) putchar('c');
		puts("");
	}
	return 0;
}