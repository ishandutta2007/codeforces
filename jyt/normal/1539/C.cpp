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
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,Bn,ans;ll m,K,A[N],B[N];
char s[N];
int main()
{
	scanf("%d%lld%lld",&n,&m,&K);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	std::sort(A+1,A+1+n);
	for(int i=1;i<n;i++) if(A[i+1]-A[i]>K) B[++Bn]=(A[i+1]-A[i]-1)/K;
	std::sort(B+1,B+1+Bn),ans=Bn+1;
	for(int i=1;i<=Bn;i++) if(m>=B[i]) m-=B[i],ans--;
	printf("%d\n",ans);
	return 0;
}