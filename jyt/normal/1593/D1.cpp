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
#define N 45
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],Min,Max;
int Solve()
{
	int val,tmp,flag;
	for(int i=Max-Min+1;i;i--)
	{
		val=A[1]%i,flag=0;
		if(val<0) val+=i;
		for(int j=2;j<=n&&!flag;j++)
		{
			tmp=A[j]%i;
			if(tmp<0) tmp+=i;
			if(tmp!=val) flag=1;
		}
		if(!flag) return i==Max-Min+1?-1:i;
	}
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		Min=Max=A[1];
		for(int i=1;i<=n;i++) Min=min(Min,A[i]),Max=max(Max,A[i]);
		printf("%d\n",Solve());
	}
	return 0;
}