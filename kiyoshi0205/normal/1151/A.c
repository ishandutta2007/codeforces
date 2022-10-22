#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int compare_char(char *a,char *b){
	return strcmp(a,b);
}

int intsort(const void *a, const void *b){
	return *(int*)a - *(int*)b;
	/*qsort(a,a,sizeof(int),intsort);*/
}

int longsort(const void *a, const void *b){
	long *A=(long *)a;
	long *B=(long *)b;
	if(*A>*B) return -1;
	if(*A<*B) return 1;
	return 0;
}

int cnt(int a,int b){
	int c=abs(a-b);
	if(c<=13){
		return c;
	}else{
		return 26-c;
	}
}


int main(){
	int i,N,s,min=200;
	char ss[51];
	scanf("%d",&N);
	scanf("%s",ss);
	for(i=0;i<N-3;i++){
		s=cnt(ss[i]-'A','A'-'A');
//		printf("%d\n",s);
		s+=cnt(ss[i+1]-'A','C'-'A');
//		printf("%d\n",s);
		s+=cnt(ss[i+2]-'A','T'-'A');
//		printf("%d\n",s);
		s+=cnt(ss[i+3]-'A','G'-'A');
//		printf("%d\n",s);
		if(min>s)min=s;
	}
	printf("%d\n",min);
	return 0;
}