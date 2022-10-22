#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int intsort(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int i,N,a[200001],b[200001]={0},c[200001]={0},count=0,ccount=0;
	scanf("%d",&N);

	for(i=0;i<200001;i++){
		a[i]=200001;
		c[i]=200001;
	}


	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,N,sizeof(int),intsort);

	b[count++]=a[0];
	for(i=1;i<N;i++){
		if(a[i-1]!=a[i]){
			b[count++]=a[i];
		}else if(c[i-1]==200001){
			c[i]=a[i];
			ccount++;
		}else{
			printf("No\n");
			return 0;
		}
	}

	qsort(c,N,sizeof(int),intsort);
	printf("Yes\n%d\n",ccount);
	for(i=0;i<ccount;i++)printf("%d ",c[i]);
	printf("\n%d\n",count);
	for(i=count-1;i>=0;i--)printf("%d ",b[i]);
	printf("\n");

	return 0;
}