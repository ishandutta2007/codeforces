#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void DFS(int i,int *L,vector<vector<int> > &e,int &N)
{
  L[N]=i;
  N++;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    DFS(j,L,e,N);
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static ll a[200000];
  for(int i=0;i<n;i++){
    scanf("%I64d",a+i);
  }
  static int p[200000];
  static ll w[200000];
  p[0]=0;
  vector<vector<int> > e(n);
  for(int i=1;i<n;i++){
    scanf("%d%I64d",p+i,w+i);
    p[i]--;
    e[p[i]].push_back(i);
  }
  int N=0;
  static int L[200000];
  DFS(0,L,e,N);
  static ll dep[200000];
  dep[0]=0;
  for(int t=1;t<n;t++){
    int i=L[t];
    dep[i]=dep[p[i]]+w[i];
  }
  static int db[200000][18];
  for(int t=0;t<n;t++){
    int i=L[t];
    db[i][0]=p[i];
    for(int k=1;k<18;k++){
      //printf("%d %d %d %d\n",i,k,db[i][k-1],p[i]);
      db[i][k]=db[db[i][k-1]][k-1];
    }
  }
  static int S[200000]={0};
  for(int t=0;t<n;t++){
    int i=L[t];
    int q=i,k=17;
    while(q>0&&k>=0){
      int r=db[q][k];
      if(dep[i]-dep[r]<=a[i]){
	q=r;
      }
      else{
	k--;
      }
    }
    if(q>0){
      S[p[q]]--;
    }
    S[i]++;
  }
  for(int t=n-1;t>0;t--){
    int i=L[t];
    S[p[i]]+=S[i];
  }
  for(int i=0;i<n;i++){
    printf("%d%c",S[i]-1,i==n-1?'\n':' ');
  }
  return 0;
}