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
int T,a,b,c;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d %d %d\n",max(max(b,c)+1-a,0),max(max(a,c)+1-b,0),max(max(a,b)+1-c,0));
	}
	return 0;
}