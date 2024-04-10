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
int T,An,n,m;
char A[N],B[N];
bool Judge(int len)
{
	if(len%m) return 0;
	for(int i=1;i<=len;i++) if(A[i]!=B[(i-1)%m+1]) return 0;
	return 1;
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%s%s",A+1,B+1),n=An=strlen(A+1),m=strlen(B+1);
		for(;!Judge(An)&&An<=n*m;) for(int i=1;i<=n;i++) A[++An]=A[i];
		if(Judge(An)) A[An+1]=0,printf("%s\n",A+1);
		else puts("-1");
	}
	return 0;
}