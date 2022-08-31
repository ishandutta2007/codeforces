#include<bits/stdc++.h>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	while(k--){
		n=n%10?n-1:n/10;
	}
	printf("%d\n",n);
	return 0;
}