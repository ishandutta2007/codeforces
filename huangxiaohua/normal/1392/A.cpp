#include<bits/stdc++.h>
using namespace std;

int n,i,t,a[200500],k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);k=0;
		scanf("%d",&a[1]);
		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==a[i-1]){k++;}
		}
		if(n==1){puts("1");continue;}
		if(k==n-1){printf("%d\n",n);}
		else{puts("1");}
	}
}