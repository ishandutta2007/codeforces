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
#define N 2005
#define M 1000005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],cnt[M],ans;
bool Solve(int p,int op)
{
	for(int i=1;i<=n;i++) cnt[A[i]]=0;
	for(int i=1;i<=n;i++) cnt[A[i]]++;
	cnt[A[p]]--,cnt[A[n]]--;int x=A[n];
	if(op) printf("%d %d\n",A[p],A[n]);
	for(int i=n;i;i--)
	{
		if(!cnt[A[i]]) continue;
		if(op) printf("%d %d\n",A[i],x-A[i]);
		cnt[A[i]]--,cnt[x-A[i]]--;
		if(cnt[x-A[i]]<0) return 0;
		x=A[i];
	}
	return 1;
}
void clear()
{
	ans=0;
	for(int i=1;i<=n;i++) cnt[A[i]]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n),n<<=1;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		std::sort(A+1,A+1+n);
		for(int i=1;i<n;i++) if(Solve(i,0)) {ans=i;break;}
		if(ans)
		{
			printf("YES\n%d\n",A[ans]+A[n]);
			Solve(ans,1);
		}
		else puts("NO");
	}
	return 0;
}