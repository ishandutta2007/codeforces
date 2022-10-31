#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > e,id;


bool V[100000]={0};
int pr[100000],prid[100000],dep[100000];
long long c[100000],s[100000];
long long ec[100000]={0};

int a,b,fi=-1;

void dfs(int i,int p)
{
  //printf("%d %d\n",i,p);
  V[i]=1;
  s[i]=0ll;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x],ei=id[i][x];
    if(j==p)continue;
    if(!V[j]){
      pr[j]=i;
      dep[j]=dep[i]+1;
      prid[j]=ei;
      dfs(j,i);
      ec[ei]=c[j]-s[j];
      s[i]+=ec[ei];
    }
    else if(fi==-1&&dep[j]<dep[i]&&(dep[i]-dep[j])%2==0){
      a=i,b=j;
      fi=ei;
    }
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  e=vector<vector<int> >(n);
  id=vector<vector<int> >(n);
  for(int i=0;i<n;i++){
    scanf("%lld",c+i);
  }
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    id[a].push_back(i);
    e[b].push_back(a);
    id[b].push_back(i);
  }
  dep[0]=0;
  dfs(0,-1);
  bool F;
  if(c[0]==s[0]){
    F=1;
  }
  else if(fi!=-1){
    F=1;
    long long x=(c[0]-s[0])/2*(dep[a]%2==0?1:-1);
    ec[fi]=x;
    int k=a,q=-1;
    while(k!=b){
      ec[prid[k]]+=q*x;
      q*=-1;
      k=pr[k];
    }
    while(k!=0){
      ec[prid[k]]+=2ll*q*x;
      q*=-1;
      k=pr[k];
    }
  }
  else{
    F=0;
  }
  if(F){
    puts("YES");
    for(int i=0;i<m;i++){
      printf("%lld\n",ec[i]);
    }
  }
  else{
    puts("NO");
  }
  return 0;
}