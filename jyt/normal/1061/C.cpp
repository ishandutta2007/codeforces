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
#define N 1000005
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,Max,A[N],f[N],ans;
std::vector<int>S[N];
int cal(int x) {x-=x<mod?0:mod;return x;}
int main()
{
	scanf("%d",&n),f[0]=1;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),Max=max(Max,A[i]);
	for(int i=Max;i;i--)
		for(int j=i;j<=Max;j+=i) S[j].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j:S[A[i]]) f[j]=cal(f[j]+f[j-1]);
	for(int i=1;i<=Max;i++) ans=cal(ans+f[i]);
	printf("%d\n",ans);
	return 0;
}