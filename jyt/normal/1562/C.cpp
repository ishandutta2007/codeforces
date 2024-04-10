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
#define N 20005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m;
char s[N];
void Solve()
{
	for(int i=m+1;i<=n;i++)
		if(s[i]=='0') {printf("1 %d 1 %d\n",i,i-1);return;}
	for(int i=1;i<=m;i++)
		if(s[i]=='0') {printf("%d %d %d %d\n",i,i+m,i+1,i+m);return;}
	printf("1 %d 2 %d\n",m,m+1);
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%s",&n,s+1),m=n>>1;
		Solve();
	}
	return 0;
}