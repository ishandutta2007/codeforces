#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100050
#define LL long long
using namespace std;
int n;
LL a[N],mx[N],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) mx[i]=1;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		mx[i]=max(mx[i],max(a[i]+1,mx[i-1]));
	}
	for(int i=n;i>=1;i--){
		ans+=mx[i]-a[i]-1;
		mx[i-1]=max(mx[i-1],mx[i]-1);
	}
	printf("%I64d\n",ans);
	return 0;
}