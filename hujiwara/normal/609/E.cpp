#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;

struct edge
{
  int a,b,i;
  long long c;
};

bool operator<(edge e1,edge e2)
{
  return e1.c<e2.c;
}

int rt(int i,int *uf)
{
  return uf[i]<0?i:uf[i]=rt(uf[i],uf);
}

void dfs(int i,int p,vector<vector<int> > &e,vector<vector<ll> > &C,int dp[200000],int db[200000][18],ll dm[200000][18])
{
  for(int j=0;j<e[i].size();j++){
    int k=e[i][j];
    if(k==p){
      continue;
    }
    dp[k]=dp[i]+1;
    db[k][0]=i;
    dm[k][0]=C[i][j];
    for(int l=1;(1<<l)<=dp[k];l++){
      db[k][l]=db[db[k][l-1]][l-1];
      dm[k][l]=max(dm[k][l-1],dm[db[k][l-1]][l-1]);
    }
    dfs(k,i,e,C,dp,db,dm);
  }
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static edge P[200000];
  for(int i=0;i<m;i++){
    int a,b;
    ll c;
    scanf("%d%d%I64d",&a,&b,&c);
    P[i].a=a-1;
    P[i].b=b-1;
    P[i].c=c;
    P[i].i=i;
  }
  sort(P,P+m);
  ll S=0;
  static int uf[200000];
  for(int i=0;i<n;i++){
    uf[i]=-1;
  }
  vector<vector<int> > E(n);
  vector<vector<ll> > C(n);
  for(int i=0;i<m;i++){
    int A=P[i].a,B=P[i].b,a=rt(A,uf),b=rt(B,uf);
    ll c=P[i].c;
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
      S+=c;
      E[A].push_back(B);
      C[A].push_back(c);
      E[B].push_back(A);
      C[B].push_back(c);
    }
  }
  static int dp[200000],db[200000][18];
  static ll dm[200000][18];
  dp[0]=0;
  dfs(0,-1,E,C,dp,db,dm);
  static ll A[200000];
  for(int i=0;i<m;i++){
    int a=P[i].a,b=P[i].b;
    if(dp[a]<dp[b]){
      swap(a,b);
    }
    ll C=0ll;
    for(int k=17;k>=0;k--){
      if((1<<k)<=dp[a]-dp[b]){
	C=max(C,dm[a][k]);
	a=db[a][k];
      }
    }
    if(a!=b){
      for(int k=17;k>=0;k--){
	if((1<<k)<=dp[a]&&db[a][k]!=db[b][k]){
	  C=max(C,max(dm[a][k],dm[b][k]));
	  a=db[a][k];
	  b=db[b][k];
	}
      }
      C=max(C,max(dm[a][0],dm[b][0]));
    }
    A[P[i].i]=S+P[i].c-C;
  }
  for(int i=0;i<m;i++){
    printf("%I64d\n",A[i]);
  }
  return 0;
}