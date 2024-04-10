#include <cstdio>

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
    long long n;
    scanf("%I64d",&n);
    bool B[2][10]={0};
    long long a[2][10][6]={0};
    bool b=0;
    B[0][0]=1;
    long long pp=1;
    while(n>0){
      for(int J=0;J<10;J++){
	if(!B[b][J]){
	  continue;
	}
	B[b][J]=0;
	int p;
	if(n%10<J){
	  p=1;
	}
	else{
	  p=0;
	}
	long long m=n-J;
	for(int i=0;i<=6;i++){
	  for(int j=0;i+j<=6;j++){
	    int k=4*i+j*7;
	    if(k%10==m%10){
	      int P=p+k/10;
	      B[!b][P]=1;
	      for(int l=0;l<6;l++){
		if(l<i){
		  a[!b][P][l]=a[b][J][l]+pp*4;
		}
		else if(l<i+j){
		  a[!b][P][l]=a[b][J][l]+pp*7;
		}
		else{
		  a[!b][P][l]=a[b][J][l];
		}
	      }
	    }
	  }
	}
      }
      n/=10;
      pp*=10;
      b=!b;
    }
    if(!B[b][0]){
      printf("-1\n");
    }
    else{
      for(int i=0;i<6;i++){
	printf("%I64d%c",a[b][0][i],i==5?'\n':' ');
      }
    }
  }
  return 0;
}