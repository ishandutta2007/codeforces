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
int n;ll Sum,cnt,ans;
struct info{ll a,b;}A[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&A[i].a,&A[i].b);
	std::sort(A+1,A+1+n,[](info t1,info t2){return t1.b<t2.b;});
	/*
	for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+A[i].a;
	for(int i=0;i<=n;i++)
	{
		if(Sum[n]-Sum[i]<A[i].b) ans=min(ans,A[i].b*2+Sum[n]-A[i].b);
		else ans=min(ans,(Sum[n]-Sum[i])*2+Sum[i]);
		dbg1(i),dbg2(ans);
	}
	*/
	for(int i=1,j=n;i<=j;i++)
	{
		for(;Sum<A[i].b&&i<=j;)
		{
			cnt=min(A[i].b-Sum,A[j].a),Sum+=cnt,ans+=cnt*2,A[j].a-=cnt;
			if(!A[j].a) j--;
		}
		if(i<=j) Sum+=A[i].a,ans+=A[i].a;
		// dbg1(i),dbg1(j),dbg2(ans);
	}
	printf("%lld\n",ans);
	return 0;
}