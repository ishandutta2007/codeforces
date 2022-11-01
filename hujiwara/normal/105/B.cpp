#include <cstdio>

long double sk(int n,int k,int A,int V[10],int L[10],int p,int a)
{
  long double M=0;
  if(p==k||a==n){
    for(int J=0;J<1<<n;J++){
      long double C=1.;
      int B=0;
      int p=0;
      for(int i=0;i<n;i++){
	if((J>>i)&1){
	  C*=L[i]/100.;
	  p++;
	}
	else{
	  C*=(100-L[i])/100.;
	  B+=V[i];
	}
      }
      if(p>n/2){
	M+=C;
      }
      else{
	M+=C*A/(A+B);
      }
    }
  }
  else{
    M=sk(n,k,A,V,L,p,a+1);
    if(L[a]<100){
      int t=L[a];
      L[a]=L[a]+10>100?100:L[a]+10;
      long double N=sk(n,k,A,V,L,p+1,a);
      if(M<N){
	M=N;
      }
      L[a]=t;
    }
  }
  return M;
}

int main()
{
  int n,k,A;
  scanf("%d%d%d",&n,&k,&A);
  int V[10],L[10];
  long double M=0;
  for(int i=0;i<n;i++){
    scanf("%d%d",V+i,L+i);
  }
  printf("%.10f\n",(double)sk(n,k,A,V,L,0,0));
  return 0;
}