#include <cstdio>

int root(int i,int *uf)
{
  return uf[i]<0?i:uf[i]=root(uf[i],uf);
}

void con(int i,int j,int *uf)
{
  i=root(i,uf);
  j=root(j,uf);
  if(i!=j){
    if(-uf[i]<-uf[j]){
      uf[i]=j;
    }
    else if(-uf[i]>-uf[j]){
      uf[j]=i;
    }
    else{
      uf[i]=j;
      uf[j]--;
    }
  }
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int a[10000],b[10000];
  for(int i=0;i<m;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--;
    b[i]--;
  }
  static int uf1[10001][500],uf2[10001][500];
  for(int i=0;i<n;i++){
    uf1[0][i]=-1;
  }
  for(int t=0;t<m;t++){
    for(int i=0;i<n;i++){
      uf1[t+1][i]=uf1[t][i];
    }
    con(a[t],b[t],uf1[t+1]);
  }
  for(int i=0;i<n;i++){
    uf2[m][i]=-1;
  }
  for(int t=m-1;t>=0;t--){
    for(int i=0;i<n;i++){
      uf2[t][i]=uf2[t+1][i];
    }
    con(a[t],b[t],uf2[t]);
  }
  int K;
  scanf("%d",&K);
  while(K--){
    int r,l;
    scanf("%d%d",&r,&l);
    r--;
    l--;
    int uf[1000];
    for(int i=0;i<n;i++){
      uf[i]=uf1[r][i];
    }
    for(int i=0;i<n;i++){
      uf[i+n]=uf2[l+1][i]<0?uf2[l+1][i]:uf2[l+1][i]+n;
    }
    for(int i=0;i<n;i++){
      con(i,i+n,uf);
    }
    int CC=0;
    for(int i=0;i<2*n;i++){
      if(uf[i]<0){
	CC++;
      }
    }
    printf("%d\n",CC);
  }
  return 0;
}