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
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		if(n&1) {puts("Bob");continue;}
		for(m=0;n%2==0;n/=2,m++);
		if(n>1) puts("Alice");
		else puts(m&1?"Bob":"Alice");
	}
	return 0;
}