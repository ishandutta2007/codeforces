#include <bits/stdc++.h>
using namespace std;

const long long INF=1000000000000000ll;

void segAdd(long long *seg,long long *segm,int i,int j,int k,int a,int b,long long d)
{
  if(a<=j&&k<=b){
    seg[i]+=d;
    segm[i]+=d;
  }
  else if(a<k&&j<b){
    segAdd(seg,segm,2*i,j,(j+k)/2,a,b,d);
    segAdd(seg,segm,2*i+1,(j+k)/2,k,a,b,d);
    segm[i]=seg[i]+min(segm[2*i],segm[2*i+1]);
  }
}

long long segMin(long long *seg,long long *segm,int i,int  j,int k,int a,int b)
{
  return a<=j&&k<=b?segm[i]:k<=a||b<=j?INF:seg[i]+min(segMin(seg,segm,2*i,j,(j+k)/2,a,b),segMin(seg,segm,2*i+1,(j+k)/2,k,a,b));
}

int n,m;

int N[300000],M[300000],t;
vector<int> e[300000];

vector<long long> UC[300000];
vector<int> V[300000],VT[300000];

void eulertour(int i,int p)
{
  N[i]=t;
  t++;
  t+=UC[i].size();
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    eulertour(j,i);
  }
  M[i]=t;
}

long long dp[300000];
long long seg[1<<21]={0},segm[1<<21]={0};

void segadd(int a,int b,long long d)
{
  segAdd(seg,segm,1,0,1<<20,a,b,d);
}

long long segmin(int a,int b)
{
  return segMin(seg,segm,1,0,1<<20,a,b);
}


void dfs(int i,int p)
{
  long long S=0ll;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs(j,i);
    if(dp[j]>=INF){
      dp[i]=INF;
      return;
    }
    S+=dp[j];
  }
  if(p!=-1){
    for(int x=0;x<V[i].size();x++){
      int j=V[i][x],s=VT[i][x];
      segadd(N[j]+s+1,N[j]+s+2,INF);
    }
  }
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    segadd(N[j],M[j],S-dp[j]);
  }
  segadd(N[i],N[i]+UC[i].size()+1,S);
  dp[i]=segmin(N[i],M[i]);
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(int i=0;i<m;i++){
    int u,v;
    long long c;
    scanf("%d%d%lld",&u,&v,&c);
    u--,v--;
    if(u==v){
      continue;
    }
    VT[v].push_back(UC[u].size());
    UC[u].push_back(c);
    V[v].push_back(u);
  }
  t=0;
  eulertour(0,-1);
  for(int i=0;i<n;i++){
    segadd(N[i],N[i]+1,INF);
    for(int x=0;x<UC[i].size();x++){
      segadd(N[i]+x+1,N[i]+x+2,UC[i][x]);
    }
  }
  dfs(0,-1);
  printf("%lld\n",n==1?0:dp[0]>=INF?-1:dp[0]);
  return 0;
}