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
#define N
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,a,b;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&a,&b);
		if(b<a*2) printf("%d\n",b-a);
		else printf("%d\n",(b-1)/2);
	}
	return 0;
}