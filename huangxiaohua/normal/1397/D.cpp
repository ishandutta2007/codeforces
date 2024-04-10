#include<bits/stdc++.h>
using namespace std;

int i,n,a[150],j,t,sum,mx;

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		sum=mx=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];mx=max(mx,a[i]);
		}
		if(n==1){
			puts("T");continue;
		}
		if(n==2){
			if(a[1]==a[2]){puts("HL");}
			else{puts("T");}
			continue;
		}
		if(sum%2){puts("T");continue;}
		if(mx*2>sum){puts("T");continue;}
		puts("HL");
	}
}