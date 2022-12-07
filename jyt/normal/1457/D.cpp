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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],Xor[N],ans=inf;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),Xor[i]=Xor[i-1]^A[i];
	for(int i=1,L,R;i<n;i++)
	{
		/*
		L=R=i;
		for(int j=i;j;j--)
			if((Xor[i]^Xor[j-1])>=A[i]) L=j;else break;
		for(int j=i+1;j<=n;j++)
			if((Xor[i]^Xor[j])<=A[i+1]) R=j;else break;
		*/
		L=max(1,i-min(ans+3,50)),R=min(n,i+min(ans+3,50));
		for(int l=L;l<=i;l++)
			for(int r=i+1;r<=R;r++) if((Xor[i]^Xor[l-1])>(Xor[i]^Xor[r])) ans=min(ans,r-l-1);
		// dbg1(i),dbg1(L),dbg2(R);
	}
	if(ans<inf) printf("%d\n",ans);
	else puts("-1");
	return 0;
}