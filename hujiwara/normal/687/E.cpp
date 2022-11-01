#include <bits/stdc++.h>
using namespace std;

const int VSIZE=5000;
const int INF=1000000;

void dfs(int i,vector<vector<int> > &e,int *B,int *N,int *low,bool *inS,stack<int> &S,int &t,int &C)
{
  N[i]=t;
  t++;
  low[i]=N[i];
  S.push(i);
  inS[i]=1;
  for(int j=0;j<e[i].size();j++){
    int k=e[i][j];
    if(N[k]==-1){
      dfs(k,e,B,N,low,inS,S,t,C);
      low[i]=min(low[i],low[k]);
    }
    else if(inS[k]){
      low[i]=min(low[i],N[k]);
    }
  }
  if(N[i]==low[i]){
    while(1){
      int j=S.top();
      S.pop();
      inS[j]=0;
      B[j]=C;
      if(j==i){
	break;
      }
    }
    C++;
  }
}

void SCC(vector<vector<int> > &e,int *B,int &C)
{
  int n=e.size();
  int N[VSIZE],low[VSIZE];
  for(int i=0;i<n;i++){
    N[i]=-1;
  }
  bool inS[VSIZE]={0};
  stack<int> S;
  int t=0;
  C=0;
  for(int i=0;i<n;i++){
    if(N[i]==-1){
      dfs(i,e,B,N,low,inS,S,t,C);
    }
  }
}


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<vector<int> > e(n);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    e[a].push_back(b);
  }
  static int C[5000];
  for(int i=0;i<n;i++){
    C[i]=0;
    static int v[5000];
    for(int j=0;j<n;j++){
      v[j]=-1;
    }
    queue<int> Q;
    Q.push(i);
    v[i]=0;
    while(!Q.empty()){
      int j=Q.front();
      Q.pop();
      for(int x=0;x<e[j].size();x++){
	int k=e[j][x];
	if(v[k]==-1){
	  v[k]=v[j]+1;
	  Q.push(k);
	}
	else if(k==i){
	  C[i]=v[j]+1;
	  goto FOUND;
	}
      }
    }
  FOUND:;
  }
  static int B[5000];
  int c;
  SCC(e,B,c);
  static int G[5000];
  for(int i=0;i<n;i++){
    G[i]=INF;
  }
  bool D[5000]={0};
  for(int i=0;i<n;i++){
    G[B[i]]=min(G[B[i]],C[i]);
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(B[j]!=B[i]){
	D[B[i]]=1;
      }
    }
  }
  int ans=n;
  for(int i=0;i<c;i++){
    if(!D[i]&&G[i]>0){
      ans+=998*G[i]+1;
    }
  }
  printf("%d\n",ans);
  return 0;
}