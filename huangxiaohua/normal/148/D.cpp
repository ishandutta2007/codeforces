#include <stdio.h>
int i,j;
double f[1050][1050];
int main(){
	for(i=1;i<=1000;i++){
		for(j=0;j<=1000;j++){
			f[i][j]=1.0*i/(i+j);
			if(i+j>2){f[i][j]+=j*(j-1)*(f[i-1][j-2]*i/(i+j-2)+f[i][j-3]*(j-2)/(i+j-2))/(i+j)/(i+j-1);}
		}
	}
	scanf("%d%d",&i,&j);
	printf("%.20lf",f[i][j]);
}