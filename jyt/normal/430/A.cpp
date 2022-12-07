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
#define N 105
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,a,b,A[N],id[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),id[i]=i;
	std::sort(id+1,id+1+n,[](int t1,int t2){return A[t1]<A[t2];});
	for(int i=1;i<=m;i++) scanf("%d%d",&a,&b);
	for(int i=1;i<=n;i++) A[id[i]]=i&1;
	for(int i=1;i<=n;i++) printf("%d ",A[i]);
	return 0;
}