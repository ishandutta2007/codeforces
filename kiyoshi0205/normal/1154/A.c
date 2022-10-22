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
	int i,a[5]={0};
	for(i=0;i<4;i++){
	scanf("%d",&a[i]);
}

	qsort(a,5,sizeof(int),intsort);

	printf("%d ",a[0]-a[1]);
	printf("%d ",a[0]-a[2]);
	printf("%d\n",a[0]-a[3]);


	return 0;
}