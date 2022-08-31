#include<bits/stdc++.h>
const int N=1e5+5;
int n,v;
int main(){
	scanf("%d%d",&n,&v);
	if(n-1<=v){
		printf("%d\n",n-1);
	}else{
		printf("%d\n",v+(n-v+2)*(n-v-1)/2);
	}
	return 0;
}