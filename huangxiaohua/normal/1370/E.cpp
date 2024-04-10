#include<stdio.h>

int i,j,n,t,k,a[1000500],b[1000500],f1,f2;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%1d",&a[i]);k+=a[i];}
	for(i=1;i<=n;i++){scanf("%1d",&b[i]);k-=b[i];}
	if(k){puts("-1");return 0;}
	for(i=1;i<=n;i++){
		if(a[i]^b[i]){
			if(a[i]){if(f2){f2--;}f1++;}
			else{if(f1){f1--;}f2++;}
		}
	}
	printf("%d",f1+f2);
}