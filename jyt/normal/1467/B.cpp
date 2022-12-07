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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],mark[N],ans;
bool Judge(int x,int y,int z)
{
	if(y>x&&y>z) return 1;
	if(y<x&&y<z) return 1;
	return 0;
}
int main()
{
	for(scanf("%d",&T);T--;ans=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=2;i<n;i++)
		{
			mark[i]=Judge(A[i-1],A[i],A[i+1]);
		}
		for(int i=1,cnt;i<n;i++)
		{
			cnt=0;
			if(mark[i+1]) cnt++;
			if(mark[i]) cnt++;
			if(mark[i-1]&&!Judge(A[i-2],A[i-1],A[i+1])) cnt++;
			if(i>2&&!mark[i-1]&&Judge(A[i-2],A[i-1],A[i+1])) cnt--;
			ans=max(ans,cnt);
		}
		for(int i=2,cnt;i<=n;i++)
		{
			cnt=0;
			if(mark[i-1]) cnt++;
			if(mark[i]) cnt++;
			if(mark[i+1]&&!Judge(A[i-1],A[i+1],A[i+2])) cnt++;
			if(i<n-1&&!mark[i+1]&&Judge(A[i-1],A[i+1],A[i+2])) cnt--;
			ans=max(ans,cnt);
		}
		ans=-ans;
		for(int i=1;i<=n;i++) ans+=mark[i],mark[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}