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
int T,n,m,x,y;ll ans;
ll Solve(int a,int b,int c,int d)
{
	return 1ll*abs(a-x)+abs(b-y)+abs(c-a)+abs(d-b)+abs(c-x)+abs(d-y);
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		ans=max(Solve(1,1,1,m),Solve(1,1,n,1));
		ans=max(ans,Solve(1,1,n,m));
		ans=max(ans,Solve(1,m,n,1));
		ans=max(ans,Solve(1,m,n,m));
		ans=max(ans,Solve(n,1,n,m));
		if(Solve(1,1,1,m)==ans) printf("1 1 1 %d\n",m);
		else if(Solve(1,1,n,1)==ans) printf("1 1 %d 1\n",n);
		else if(Solve(1,1,n,m)==ans) printf("1 1 %d %d\n",n,m);
		else if(Solve(1,m,n,1)==ans) printf("1 %d %d 1\n",m,n);
		else if(Solve(1,m,n,m)==ans) printf("1 %d %d %d\n",m,n,m);
		else if(Solve(n,1,n,m)==ans) printf("%d 1 %d %d\n",n,n,m);
	}
	return 0;
}