#include<bits/stdc++.h>
using namespace std;

int i,n,t,sb,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=2*n-1;i++){
			scanf("%1d",&sb);
			if(i==n){res=sb;}
		}
		for(i=1;i<=n;i++){
			printf("%d",res);
		}puts("");
	}
	
}