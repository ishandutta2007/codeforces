#include<bits/stdc++.h>
using namespace std;
int i,t,n,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(k>=n){
			printf("%d\n",k-n);continue;
		}
		if((k%2)!=(n%2)){
			puts("1");continue;
		}
		puts("0");
	}
}