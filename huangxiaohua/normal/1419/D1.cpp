#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,t,n,a[100500],res[100500];

int main(){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		printf("%d\n",(n-1)/2);
		for(i=1,j=n;i<=n;i+=2,j--){
			res[i]=a[j];
		}
		for(i=2;i<=n;i+=2,j--){
			res[i]=a[j];
		}
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}puts("");
}