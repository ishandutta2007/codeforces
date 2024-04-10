// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include <ctime>
#define LL long long
#define ept 1e-10
#define pa pair<int,int>
using namespace std;
const int N=1000050;
const LL mod=1e9+7;
int n,m;
LL a[N];
int main(){
	scanf("%d",&n);m=n;n<<=1;
	for(int i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	LL ans=(a[m]-a[1])*(a[n]-a[m+1]);
	for(int i=2;i+m-1<n;++i)
		ans=min(ans,(a[n]-a[1])*(a[i+m-1]-a[i]));
	printf("%I64d\n",ans);
	return 0;
}