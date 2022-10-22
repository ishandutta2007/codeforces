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
	int i,N,Acc,Bat,s,a,b;
	scanf("%d",&N);
	scanf("%d",&Bat);
	b=Bat;
	scanf("%d",&Acc);
	a=Acc;
	for(i=0;i<N;i++){
//		printf("b=%d,a=%d\n",b,a);
		scanf("%d",&s);
		if(s==0){
			if(a>0){
				a--;
				continue;
			}else if(b>0){
				b--;
				continue;
			}else{
				break;
			}
		}else{
			if(a==Acc){
				a--;
				continue;
			}else if(b>0){
				b--;
				a++;
				continue;
			}else if(a>0){
				a--;
				continue;
			}else{
				break;
			}
		}
	}
	printf("%d\n",i);
	return 0;
}