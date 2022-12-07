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
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		for(int i=1;i<=n;i++) printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(i&1) printf("%d ",i/2+1);
		else printf("%d ",n-i/2+1);
	}
	for(int i=1;i<=n-m;i++) printf("%d ",m&1?m/2+i+1:n-m/2-i+1);
	return 0;
}