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
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(m>(n+1)*2||n>m+1) return puts("-1"),0;
	if(n==m+1) printf("0"),n--;
	for(;m>n&&m>1&&n;) printf("110"),m-=2,n--;
	if(m==2&&!n) puts("11"),m=0;
	for(int i=1;n||m;i^=1) printf("%d",i),i?m--:n--;
	return 0;
}