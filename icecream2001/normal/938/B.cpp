#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define N 100050
using namespace std;
int n,ans=1000000000;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	a[0]=1;a[n+1]=1000000;
	for(int i=0;i<=n;i++){
		ans=min(ans,max(a[i]-a[0],a[n+1]-a[i+1]));
	}
	printf("%d\n",ans);
	return 0;
}