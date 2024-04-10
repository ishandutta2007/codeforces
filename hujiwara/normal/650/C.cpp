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
  int n,m;
  scanf("%d%d",&n,&m);
  static int a[10000000];
  int N=n*m;
  for(int i=0;i<N;i++){
    scanf("%d",a+i);
  }
  static pair<int,int> A[1000000];
  static vector<int> e[1000000];
  static int uf[1000000]={0};
  for(int i=0;i<N;i++){
    uf[i]=-1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      A[j]=make_pair(a[i*m+j],j);
    }
    sort(A,A+m);
    for(int j=0;j+1<m;j++){
      int p=i*m+A[j].second,q=i*m+A[j+1].second;
      if(A[j].first<A[j+1].first){
	e[p].push_back(q);
      }
      else{
	con(uf,p,q);
      }
    }
  }
  for(int j=0;j<m;j++){
    for(int i=0;i<n;i++){
      A[i]=make_pair(a[i*m+j],i);
    }
    sort(A,A+n);
    for(int i=0;i+1<n;i++){
      int p=A[i].second*m+j,q=A[i+1].second*m+j;
      if(A[i].first<A[i+1].first){
	e[p].push_back(q);
      }
      else{
	con(uf,p,q);
      }
    }
  }
  static vector<int> E[1000000];
  static int D[1000000]={0};
  for(int i=0;i<N;i++){
    int a=rt(uf,i);
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      int b=rt(uf,j);
      E[a].push_back(b);
      D[b]++;
    }
  }
  static int V[1000000]={0};
  queue<int> Q;
  for(int i=0;i<N;i++){
    if(uf[i]<0&&D[i]==0){
      V[i]=1;
      Q.push(i);
    }
  }
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    for(int x=0;x<E[i].size();x++){
      int j=E[i][x];
      V[j]=max(V[j],V[i]+1);
      D[j]--;
      if(D[j]==0){
	Q.push(j);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d%c",V[rt(uf,i*m+j)],j+1<m?' ':'\n');
    }
  }
  return 0;
}