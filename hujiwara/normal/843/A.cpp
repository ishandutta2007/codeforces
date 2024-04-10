#include <bits/stdc++.h>
using namespace std;

int rt(vector<int> &uf,int i)
{
  return uf[i]<0?i:uf[i]=rt(uf,uf[i]);
}

void con(vector<int> &uf,int a,int b)
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
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
  }
  vector<pair<int,int> > P(n);
  for(int i=0;i<n;i++){
    P[i]=make_pair(a[i],i);
  }
  sort(P.begin(),P.end());
  vector<bool> B(n,0);
  vector<vector<int> > T;
  for(int i=0;i<n;i++){
    if(B[i]){
      continue;
    }
    B[i]=1;
    vector<int> V(1,i);
    int j=P[i].second;
    while(j!=i){
      B[j]=1;
      V.push_back(j);
      j=P[j].second;
    }
    T.push_back(V);
  }
  printf("%d\n",(int)T.size());
  for(int i=0;i<T.size();i++){
    printf("%d",(int)T[i].size());
    for(int x=0;x<T[i].size();x++){
      printf(" %d",T[i][x]+1);
    }
    putchar('\n');
  }
  return 0;
}