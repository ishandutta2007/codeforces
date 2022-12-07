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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,l,r,lmid,rmid,lv,rv,a,b;
int main()
{
	scanf("%d",&n),l=0,r=n+1,lv=rv=inf;
	for(;r-l>2;)
	{
		rmid=(l+r+1)>>1,lmid=(l+rmid)>>1;
		// dbg1(l),dbg1(r),dbg1(lmid),dbg2(rmid);
		printf("? %d\n",lmid),fflush(stdout),scanf("%d",&a);
		printf("? %d\n",rmid),fflush(stdout),scanf("%d",&b);
		if(a<b) r=rmid,rv=b;else l=lmid,lv=a;
	}
	printf("! %d\n",l+r>>1);
	return 0;
}
/*
5
3 2 1 4 5
*/