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
int T,a,b,c;ll tot;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d",&a,&b,&c);
		tot=(ll)b*c+c;
		// dbg2(tot);
		printf("%lld\n",c+(tot-2)/(a-1)+1);
	}
	return 0;
}