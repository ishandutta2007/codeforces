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
#define N 505
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,A[N],B[N],Bn,pos[N],mark[N],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1,a;i<=m;i++)
	{
		scanf("%d",&a);
		if(!mark[a]) B[++Bn]=a,pos[a]=Bn,mark[a]=1;
		for(int j=pos[a]-1;j;j--) B[j+1]=B[j],pos[B[j]]=j+1,ans+=A[B[j]];
		B[1]=a,pos[a]=1;
	}
	printf("%d\n",ans);
	return 0;
}