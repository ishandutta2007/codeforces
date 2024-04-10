#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare_char(char *a,char *b){
	return strcmp(a,b);
}

int main(){
	int i,j,f=0,N;
	scanf("%d",&N);
	char ss[102];


	for(i=0;i<N;i++){
		scanf("%s",ss);
		if(strlen(ss)==1){
			printf("Yes\n");
			continue;
		}
		qsort(ss,strlen(ss),sizeof(char),compare_char);
		for(j=0;j<strlen(ss)-1;j++){
			if(ss[j]+1!=ss[j+1])f=1;
		}
		if(f==0){
			printf("Yes\n");
		}else{
			printf("No\n");
			f=0;
		}
	}

}