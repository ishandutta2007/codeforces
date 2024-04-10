#include<bits/stdc++.h>
int w,h,k;
int main(){
	scanf("%d%d%d",&w,&h,&k);
	printf("%d\n",((w+h)*4-k*16+8)*k/2);
	return 0;
}