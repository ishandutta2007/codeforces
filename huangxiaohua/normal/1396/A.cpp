#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll i,n,res,a[100500],j,k,tmp,sb;
 
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	if(n==1){
		puts("1 1");
		printf("%lld\n",-a[1]);
		puts("1 1\n0");puts("1 1\n0");return 0;
	}
	
	printf("1 %lld\n",n-1);
	
	for(i=1;i<=n-1;i++){
		sb=((a[i]%n)+n)%n;
		printf("%lld ",sb*(n-1));
		a[i]+=sb*(n-1);
	}puts("");
	
	//for(i=1;i<=n;i++){printf("%lld ",a[i]);}puts("");puts("");
	
	printf("2 %lld\n",n);
	for(i=2;i<=n;i++){
		sb=((a[i]%n)+n)%n;
		printf("%lld ",sb*(n-1));
		a[i]+=sb*(n-1);
	}puts("");
	
	//for(i=1;i<=n;i++){printf("%lld ",a[i]);}puts("");puts("");
	
	printf("1 %lld\n",n);
	for(i=1;i<=n;i++){
		printf("%lld ",-a[i]);
	}puts("");
}