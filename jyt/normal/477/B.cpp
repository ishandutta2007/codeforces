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
int n,m,cnt,flag,mark[N],ans[N][5];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",(n*6-1)*m);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",(i*6-5)*m,(i*6-4)*m,(i*6-3)*m,(i*6-1)*m);
	}
	return 0;
}