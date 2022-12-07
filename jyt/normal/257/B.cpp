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
int n,m,a,b,ans1,ans2,ans3,ans4;
void Solve(int x,int y)
{
	ans1=ans2=0;int pre=0;
	if(x) x--;else pre=1,y--;
	for(int i=2,v;i<=n+m;i++)
	{
		v=i&1?pre^1:pre;
		if(v&&!y||!v&&!x) v^=1;
		v?y--:x--,v^pre?ans2++:ans1++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	Solve(n,m),ans3=ans1,ans4=ans2,Solve(m,n);
	if(ans1>ans3||ans1==ans3&&ans2<ans4) printf("%d %d\n",ans1,ans2);
	else printf("%d %d\n",ans3,ans4);
	return 0;
}