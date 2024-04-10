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
int T,a1,b1,c1,a2,b2,c2,tmp,ans;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
		tmp=min(a1,c2),a1-=tmp,c2-=tmp;
		tmp=min(c1,c2),c1-=tmp,c2-=tmp;
		printf("%d\n",-2*min(b1,c2)+2*min(c1,b2));
	}
	return 0;
}