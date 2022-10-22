#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int max(int a,int b){
	if(a>b)return a;
	return b;
}

int min(int a,int b){
	if(a<b)return a;
	return b;
}

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
  int i,N,bf,now,f=0;
  long cnt=0;
  scanf("%d",&N);
  scanf("%d",&bf);
  for(i=1;i<N;i++){
    scanf("%d",&now);
    if(now*bf==6){
      printf("Infinite\n");
      return 0;
    }
    switch(now){
      case 1:
        if(bf==2){
          cnt+=3;
        }else{
          f=1;
          cnt+=4;
        }
        break;
      case 2:
        if(f==1){
          cnt+=2;
          f=0;
        }else{
          cnt+=3;
        }
        break;
      case 3:
        f=0;
        cnt+=4;
        break;
    }
    bf=now;
  }

  printf("Finite\n%ld",cnt);
  return 0;
}