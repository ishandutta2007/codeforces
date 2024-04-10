#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int intsort(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int i,N,a,oddcount=0,odd[2001],evencount=0,even[2001],count,ans=0;
	scanf("%d",&N);

	for(i=0;i<2001;i++){
		odd[i]=10000001;
		even[i]=10000000;
	}

	for(i=0;i<N;i++){
		scanf("%d",&a);
		switch(a%2){
		case 0:
			odd[oddcount++]=a;
			break;
		case 1:
			even[evencount++]=a;
			break;
		}
	}


	count=abs(oddcount-evencount);
	if(count<=1){
		printf("0\n");
		return 0;
	}else if(oddcount>evencount){
		qsort(odd,2001,sizeof(int),intsort);
		for(i=0;i<count-1;i++){
			ans+=odd[i];
		}
	}else{
		qsort(even,2001,sizeof(int),intsort);
		for(i=0;i<count-1;i++){
			ans+=even[i];
		}
	}
	printf("%d\n",ans);

	return 0;
}