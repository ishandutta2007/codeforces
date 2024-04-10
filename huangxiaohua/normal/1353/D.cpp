#include<stdio.h>
int t,i,j,n,a[200005][2],len,sum,max,maxn,b[200005];
int main(){
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld",&n);
		
		if(n==1){printf("1\n");continue;}
		if(n==2){printf("1 2\n");continue;}
		if(n==3){printf("2 1 3\n");continue;}
		
		len=n;sum=0;a[0][0]=11451419;
		for(j=1;j<=n;j++){
			a[j][0]=0;
		}
		while(sum!=n){
			max=0;maxn=0;
			for(j=1;j<=n;j++){
				if(a[j][0]==0){a[j][1]=a[j-1][1]+1;}
				else{a[j][1]=0;}
				if(a[j][1]==max){maxn++;b[maxn]=j;continue;}
				if(a[j][1]>max){maxn=1;max=a[j][1];b[maxn]=j;continue;}
			}
			//for(j=1;j<=n;j++){printf("a%d ",a[j][1]);}
			//printf("b%d\n",maxn);
			for(j=1;j<=maxn;j++){
				sum++;a[b[j]-max/2][0]=sum;
			}
		}
		for(j=1;j<=n;j++){
			printf("%d ",a[j][0]);
		}
		printf("\n");
	}

}