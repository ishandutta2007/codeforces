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
int T,n,m,flag;
int Solve(int x,int y,int l)
{
	if(x>y) return 0;
	if(!l) return y?2:1;
	int v1=x>>l&1,v2=y>>l&1;
	x-=v1<<l,y-=v2<<l;
	int res=Solve(x,y,l-1);
	// if(res==(1<<l)&&v2) res+=1<<l;
	if(!v1&&v2) res+=1<<l;
	if(v1&&v2&&res==(1<<l)) res+=1<<l;
	return res;
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",Solve(n,m,30));
	}
	return 0;
}