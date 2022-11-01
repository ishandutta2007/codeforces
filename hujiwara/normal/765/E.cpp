#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > e;

int r=-1;

int dfs(int i,int p,bool F)
{
  vector<int> R;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    int k=dfs(j,i,F);
    if(k==-1){
      return -1;
    }
    R.push_back(k+1);
  }
  int K=R.size();
  if(K==0){
    return 0;
  }
  bool G=0;
  for(int x=1;x<K;x++){
    if(R[0]!=R[x]){
      G=1;
    }
  }
  if(G){
    if(!F){
      r=i;
    }
    return -1;
  }
  return R[0];
}

int main()
{
  int n;
  scanf("%d",&n);
  e=vector<vector<int> >(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  r=-1;
  int ret=dfs(0,-1,0);
  if(ret==-1){
    //printf("%d\n",r);
    vector<int> V;
    bool F=0;
    for(int x=0;x<e[r].size();x++){
      int j=e[r][x];
      int k=dfs(j,r,1);
      //printf("%d\n",k);
      if(k==-1){
	F=1;
	break;
      }
      V.push_back(k+1);
    }
    if(!F){
      sort(V.begin(),V.end());
      int K=V.size();
      for(int i=0;i<K;i++){
	if(V[i]!=V[0]&&V[i]!=V[K-1]){
	  F=1;
	}
      }
      if(!F){
	ret=V[0]+V[K-1];
      }
    }
  }
  while(ret%2==0){
    ret/=2;
  }
  printf("%d\n",ret);
  return 0;
}