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
  int i,t=10,N,a[200001],f[10],cnt[10]={0};
  char ss[200001];
  scanf("%d",&N);
  scanf("%s",ss);
  for(i=0;i<10;i++){
    scanf("%d",&f[i]);
    if(f[i]-1>i)cnt[i]=f[i];
    if(f[i]-1==i)cnt[i]=-1;
  }

  for(i=0;i<N;i++){
    t=ss[i]-'1';
    if(cnt[t]>0){
      printf("%d",cnt[t]);
      i++;
      break;
    }else{
      printf("%c",ss[i]);
    }
  }
  
  while(i<N){
    t=ss[i]-'1';
    if(cnt[t]==0){
      printf("%c",ss[i]);
      i++;
      break;
    }else if(cnt[t]==-1){
      printf("%c",ss[i]);
    }else{
      printf("%d",cnt[t]);
    }
    i++;
  }
  while(i<N){
    printf("%c",ss[i]);
    i++;
  }
  printf("\n");
  return 0;
}