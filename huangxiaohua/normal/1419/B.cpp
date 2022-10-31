#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,n,t,res;
long long sb[66],p[66],k;

int main(){

	p[0]=1;
	for(i=1;i<=60;i++){
		p[i]=p[i-1]*2;
		sb[i]=p[i]*(p[i]-1)/2;
	}
	
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&k);res=0;
		for(i=1;k>=sb[i];i++){
			res++;k-=sb[i];
		}
		printf("%d\n",res);
	}
}