#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,t,kk,kkk,tmp;
long long sum,n,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);sum=kkk=0;kk=1;
		for(i=1;i<=n;i++){
			scanf("%d",&tmp);sum+=tmp;
			if(tmp!=k){kk=0;}
			if(tmp==k){kkk=1;}
		}
		if(kk){puts("0");continue;}
		if(sum==(k*n)||kkk){puts("1");continue;}
		puts("2");
	}
}