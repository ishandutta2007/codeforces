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
int T,a,b,c,d;
int F(int x,int y) {return abs(c-x)+abs(d-y);}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",max(max(F(1,1),F(1,b)),max(F(a,1),F(a,b))));
	}
	return 0;
}