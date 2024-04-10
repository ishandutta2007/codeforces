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
int n,m,a,b,c;ll A[N],B[N],Sum;
void add(int x,int v)
{
	if(x==1||x>n) return;
	Sum-=max(B[x],0ll),B[x]+=v,Sum+=max(B[x],0ll);
}
void Solve() {ll x=A[1]-Sum>>1;printf("%lld\n",max(x+Sum,A[1]-x));}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]),B[i]=A[i]-A[i-1],Sum+=max(B[i],0ll);
	if(B[1]>0) Sum-=B[1];Solve();
	for(scanf("%d",&m);m--;)
	{
		scanf("%d%d%d",&a,&b,&c),add(a,c),add(b+1,-c);
		if(a==1) A[1]+=c;Solve();
	}
	return 0;
}