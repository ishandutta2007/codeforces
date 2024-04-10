#include<bits/stdc++.h>
int n,k,a;
int main(){
	scanf("%d%d",&n,&k);
	a=(n-k)>>1;
	for(int i=1;i<=n;++i)
		putchar('0'+(i%(a+1)==0));
	return 0;
}