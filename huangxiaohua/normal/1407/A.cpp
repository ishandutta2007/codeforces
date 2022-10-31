#include<bits/stdc++.h>
using namespace std;
 
int i,j,n,t,x,one,zero;
 
int main(){
	scanf("%d",&t);
	while(t--){
		one=zero=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(x){one++;}
			else{zero++;}
		}
		if(one>zero){
			printf("%d\n",one-one%2);
			for(i=1;i<=one-one%2;i++){
				printf("1 ");
			}
		}
		else{
			printf("%d\n",zero);
			for(i=1;i<=zero;i++){
				printf("0 ");
			}
		}
		puts("");
	}
}