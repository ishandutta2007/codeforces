#include <bits/stdc++.h>
using namespace std;

long long n,i,t,x,a[100500],res,j,tmp;
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d%d",&n,&x);res=j=tmp=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(i=n;i>=1;i--){
			j++;
			if(a[i]*j>=x){res++;j=0;}
		}
		printf("%lld\n",res);
	}
}