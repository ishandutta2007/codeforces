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
int n,A[N],last[N],nex[N],val1,val2,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=N-5;i++) last[i]=n+1;
	for(int i=n;i;i--) nex[i]=last[A[i]],last[A[i]]=i;
	nex[0]=n+1;
	for(int i=1;i<=n;i++)
	{
		if(A[val1]!=A[i]&&A[val2]==A[i]) {val1=i,ans++;continue;}
		if(A[val1]==A[i]&&A[val2]!=A[i]) {val2=i,ans++;continue;}
		if(nex[val1]<nex[val2]) ans+=(A[val1]!=A[i]),val1=i;
		else ans+=(A[val2]!=A[i]),val2=i;
		// dbg1(i),dbg1(val1),dbg1(val2),dbg1(nex[i]),dbg2(ans);
	}
	printf("%d\n",ans);
	return 0;
}
/*
5
1 2 1 1 1
*/