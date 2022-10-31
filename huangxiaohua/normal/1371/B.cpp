#include<bits/stdc++.h>
using namespace std;

long long int i,n,a,b;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%lld%lld",&a,&b);
		if(b<=a-1){printf("%lld\n",(1+b)*b/2);continue;}
		printf("%lld\n",(a-1)*a/2+1);
		
	}
}