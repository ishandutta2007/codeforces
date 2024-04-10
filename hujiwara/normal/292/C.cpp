#include <cstdio>

int K=0,U[100000][4];

void pre(int s[13],int i,int l,int p,int A[4])
{
  if(3*(4-p)<l-i||4-p>l-i){
    return;
  }
  if(p==4){
    for(int k=0;k<4;k++){
      U[K][k]=A[k];
    }
    K++;
    return;
  }
  if(s[i]<256){
    A[p]=s[i];
    pre(s,i+1,l,p+1,A);
  }
  if(i+1<l&&s[i]!=0&&10*s[i]+s[i+1]<256){
    A[p]=10*s[i]+s[i+1];
    pre(s,i+2,l,p+1,A);
  }
  if(i+2<l&&s[i]!=0&&100*s[i]+10*s[i+1]+s[i+2]<256){
    A[p]=100*s[i]+10*s[i+1]+s[i+2];
    pre(s,i+3,l,p+1,A);
  }
}

int main()
{
  int a[10]={0};
  int n;
  scanf("%d",&n);
  while(n--){
    int k;
    scanf("%d",&k);
    a[k]=1;
  }
  int KKK=1;
  for(int p=1;p<=6;p++){
    KKK*=10;
    for(int I=0;I<KKK;I++){
      int J=I;
      bool b=0;
      bool B[10]={0};
      for(int i=0;i<p;i++){
	if(!a[J%10]){
	  b=1;
	}
	B[J%10]=1;
	J/=10;
      }
      for(int i=0;i<10;i++){
	if(a[i]&&!B[i]){
	  b=1;
	}
      }
      if(b){
	continue;
      }
      int s[13];
      J=I;
      for(int i=0;i<p;i++){
	s[i+p]=s[p-i-1]=J%10;
	J/=10;
      }
      int A[4];
      pre(s,0,2*p,0,A);
      J=I;
      for(int i=0;i<p;i++){
	s[i+p-1]=s[p-i-1]=J%10;
	J/=10;
      }
      pre(s,0,2*p-1,0,A);
    }
  }
  printf("%d\n",K);
  for(int i=0;i<K;i++){
    printf("%d.%d.%d.%d\n",U[i][0],U[i][1],U[i][2],U[i][3]);
  }
  return 0;
}