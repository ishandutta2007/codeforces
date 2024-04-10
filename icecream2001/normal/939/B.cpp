#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
#define N 100050
using namespace std;
LL n;
LL a[N];
int k,ans;
int main(){
    scanf("%I64d%d",&n,&k);ans=1;
    for(int i=1;i<=k;i++){
    	scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=k;i++){
		if((n%a[i])<(n%a[ans])){
			ans=i;
		}
	}
	printf("%d ",ans);
	n=n/a[ans];
	printf("%I64d\n",n);
	return 0;
}