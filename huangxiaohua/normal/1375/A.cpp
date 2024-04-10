#include<bits/stdc++.h>
using namespace std;

int i,n,t,res;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		for(i=1;i<=t;i++){
			scanf("%d",&res);
			if(i%2==1){
				printf("%d ",abs(res));
			}
			else{
				printf("%d ",-abs(res));
			}
		}
		puts("");
	}
}