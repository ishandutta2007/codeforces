#include <bits/stdc++.h>
using namespace std;

int rt(int *uf,int i)
{
  return uf[i]<0?i:uf[i]=rt(uf,uf[i]);
}

void con(int *uf,int a,int b)
{
  a=rt(uf,a);
  b=rt(uf,b);
  if(a!=b){
    if(-uf[a]<-uf[b]){
      uf[a]=b;
    }
    else if(-uf[a]>-uf[b]){
      uf[b]=a;
    }
    else{
      uf[a]=b;
      uf[b]--;
    }
  }
}

int main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int c[1000];
  for(int i=0;i<k;i++){
    scanf("%d",c+i);
    c[i]--;
  }
  int uf[1000];
  for(int i=0;i<n;i++){
    uf[i]=-1;
  }
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    con(uf,a,b);
  }
  int S[1000]={0};
  for(int i=0;i<n;i++){
    int r=rt(uf,i);
    S[r]++;
  }
  int M=0,A=0,N=n;
  for(int i=0;i<k;i++){
    int r=rt(uf,c[i]),s=S[r];
    M=max(M,s);
    A+=s*(s-1)/2;
    N-=s;
  }
  printf("%d \n",A-M*(M-1)/2+(M+N)*(M+N-1)/2-m);
  return 0;
}