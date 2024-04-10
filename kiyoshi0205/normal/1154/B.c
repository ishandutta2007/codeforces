#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int compare_char(char *a,char *b){
	return strcmp(a,b);
}

int intsort(const void *a, const void *b){
	return *(int*)b - *(int*)a;
	/*qsort(a,a,sizeof(int),intsort);*/
}

int longsort(const void *a, const void *b){
	long *A=(long *)a;
	long *B=(long *)b;
	if(*A>*B) return -1;
	if(*A<*B) return 1;
	return 0;
}

int main(){
	int i,N,j,p,a[4]={0},cnt=0;
	scanf("%d",&N);
	if(N==1){
		printf("0\n");
		return 0;
	}
	for(i=0;i<N;i++){
	scanf("%d",&p);
	if(a[0]==0)a[0]=p;
	if(a[0]==p)continue;
	if(a[1]==0)a[1]=p;
	if(a[1]==p)continue;
	if(a[2]==0)a[2]=p;
	if(a[2]==p)continue;
	printf("-1");
	return 0;
	}
	qsort(a,4,sizeof(int),intsort);
	if(a[1]==0){
		printf("0\n");
		return 0;
	}
	if(a[2]==0){
		if((a[0]+a[1])%2 ==0){
			printf("%d\n",(a[0]-a[1])/2);
			return 0;
		}else{
		printf("%d\n",a[0]-a[1]);
		return 0;
		}
	}
	if(a[0]+a[2]!=2*a[1]){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",a[0]-a[1]);
	return 0;
}