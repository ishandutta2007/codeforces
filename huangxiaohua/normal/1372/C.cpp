#include <bits/stdc++.h>
using namespace std;
 
int n,i,t,b,res,k,a[200500],kk;
 
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);k=0;kk=1;res=0;
		for(i=1;i<=t;i++){
			scanf("%d",&b);
			if(b!=i){a[i]=1;k=1;}
			else{a[i]=0;}
		}
		for(i=1;i<=t;i++){
			if(a[i]==1){res+=kk;kk=0;}
			else{kk=1;}
		}
		if(res>1){k=2;
		}
		printf("%d\n",k);
	}
}