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
int n,m,val;
int main()
{
	scanf("%d%d",&n,&m),val=m-n/2+1;
	if(n==1&&m||val<1) return puts("-1"),0;
	if(n==1&&!m) return puts("1"),0;
	printf("%d %d ",val,val*2),val*=2;
	for(int i=3;i<=n;i++) printf("%d ",++val);
	return 0;
}