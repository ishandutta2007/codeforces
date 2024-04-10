#include<stdio.h>
#include<math.h>
int i,n[12];
double sb;
int main(){
	for(i=1;i<=11;i++){
		scanf("%d",&n[i]);
	}
	for(i=11;i>=1;i--){

		sb=5*n[i]*n[i]*n[i]+sqrt(abs(n[i]));
		if(sb>=400){
			printf("f(%d) = MAGNA NIMIS!\n",n[i]);
		}
		else{
			printf("f(%d) = %.2lf\n",n[i],sb);
		}
	
}}