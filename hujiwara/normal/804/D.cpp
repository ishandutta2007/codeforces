#include <bits/stdc++.h>
using namespace std;

const int MN=100000;

int ht[MN],dia[MN];
int n;
vector<int> e[MN];
int con[MN];

void dfs1(int i,int p,int c)
{
  con[i]=c;
  ht[i]=0;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs1(j,i,c);
    ht[i]=max(ht[i],ht[j]+1);
  }
}

void dfs2(int i,int p,int X)
{
  int mx=0,mj,mx2=0;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    if(ht[j]+1>mx){
      mx2=mx;
      mx=ht[j]+1;
      mj=j;
    }
    else if(ht[j]+1>mx2){
      mx2=ht[j]+1;
    }
  }
  dia[i]=max(X,mx);
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs2(j,i,max(X,j==mj?mx2:mx)+1);
  }
}

int main()
{
  int m,q;
  scanf("%d%d%d",&n,&m,&q);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    con[i]=-1;
  }
  int C=0;
  for(int i=0;i<n;i++){
    if(con[i]!=-1){
      continue;
    }
    dfs1(i,-1,C);
    C++;
    dfs2(i,-1,0);
  }
  vector<int> sz(C,0),Dia(C,0);
  vector<vector<int> > dis(C);
  for(int i=0;i<n;i++){
    sz[con[i]]++;
    Dia[con[i]]=max(Dia[con[i]],dia[i]);
  }
  for(int t=0;t<C;t++){
    dis[t]=vector<int>(sz[t]+1,0);
  }
  for(int i=0;i<n;i++){
    dis[con[i]][dia[i]]++;
  }
  vector<vector<double> > sdis(C),edis(C);
  for(int t=0;t<C;t++){
    sdis[t]=vector<double>(sz[t]+2,0.);
    edis[t]=vector<double>(sz[t]+2,0.);
    sdis[t][0]=0.;
    edis[t][0]=0.;
    for(int x=0;x<=sz[t];x++){
      //printf("%d %d %d\n",t,x,dis[t][x]);
      sdis[t][x+1]=sdis[t][x]+(double)dis[t][x]/sz[t];
      edis[t][x+1]=edis[t][x]+(double)x*dis[t][x]/sz[t];
    }
  }
  map<pair<int,int>,double> memo;
  while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    a=con[a],b=con[b];
    if(a==b){
      puts("-1");
      continue;
    }
    if(sz[a]>sz[b]){
      swap(a,b);
    }
    double ans;
    if(memo.find(make_pair(a,b))!=memo.end()){
      ans=memo[make_pair(a,b)];
    }
    else{
      ans=0.;
      int D=max(Dia[a],Dia[b]);
      for(int x=0;x<=Dia[a];x++){
	int Y=min(D-x,sz[b]+1);
	ans+=(double)dis[a][x]/sz[a]*(D*sdis[b][Y]+(x+1)*(sdis[b][sz[b]+1]-sdis[b][Y])+edis[b][sz[b]+1]-edis[b][Y]);
      }
      memo[make_pair(a,b)]=ans;  
    }
    printf("%.8lf\n",ans);
  }
  return 0;
}