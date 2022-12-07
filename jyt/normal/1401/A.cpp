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
int T,n,m,ans;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		if(n-m<0) printf("%d\n",m-n);
		else puts(n-m&1?"1":"0");
	}
	return 0;
}