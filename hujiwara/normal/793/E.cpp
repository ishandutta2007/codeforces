#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[10000];
int sz[10000];

void dfs(int i,int t,bool &F,bool *A)
{
  sz[i]=(e[i].size()==0?1:0);
  F=0;
  int nj=0;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    bool f;
    dfs(j,t,f,A);
    sz[i]+=sz[j];
    if(f){
      F=1;
      nj=j;
    }
  }
  if(i==t){
    F=1;
    A[0]=1;
    for(int y=1;y<n;y++){
      A[y]=0;
    }
  }
  else if(F){
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(j==nj){
	continue;
      }
      for(int y=n-1;y>=sz[j];y--){
	A[y]|=A[y-sz[j]];
      }
    }
  }
}

int main()
{
  scanf("%d",&n);
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  a--,b--,c--,d--;
  for(int i=1;i<n;i++){
    int p;
    scanf("%d",&p);
    p--;
    e[p].push_back(i);
  }
  int nof=0;
  for(int i=0;i<n;i++){
    if(e[i].size()==0){
      nof++;
    }
  }
  if(nof%2==1){
    puts("NO");
    return 0;
  }
  //printf("%d %d %d %d\n",a,b,c,d);
  bool A[10010],B[10010],C[10010],D[10010];
  int aj,bj,cj,dj;
  for(int x=0;x<e[0].size();x++){
    int j=e[0][x];
    //printf("%d\n",j);
    bool F;
    dfs(j,a,F,A);
    if(F){
      aj=j;
    }
    dfs(j,b,F,B);
    if(F){
      bj=j;
    }
    dfs(j,c,F,C);
    if(F){
      cj=j;
    }
    dfs(j,d,F,D);
    if(F){
      dj=j;
    }
  }
  static bool b1[10010]={0},b2[10010]={0};
  for(int i=0;i<sz[aj];i++){
    for(int j=0;j<sz[bj];j++){
      b1[i+j+sz[cj]]|=A[i]&&B[j];
    }
  }
  for(int i=0;i<sz[cj];i++){
    for(int j=0;j<sz[dj];j++){
      b2[i+j+sz[bj]]|=C[i]&&D[j];
    }
  }
  for(int x=0;x<e[0].size();x++){
    int j=e[0][x];
    if(j==aj||j==bj||j==cj||j==dj){
      continue;
    }
    for(int y=n-1;y>=sz[j];y--){
      b1[y]|=b1[y-sz[j]];
      b2[y]|=b2[y-sz[j]];
    }
  }
  puts(b1[nof/2-1]&&b2[nof/2-1]?"YES":"NO");
  return 0;
}