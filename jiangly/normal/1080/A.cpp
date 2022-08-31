#include<bits/stdc++.h>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",int(ceil(n*2.0/k)+ceil(n*5.0/k)+ceil(n*8.0/k)));
	return 0;
}