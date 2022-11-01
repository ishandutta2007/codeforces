#include <bits/stdc++.h>
using namespace std;
bool ans[200000]={0};
bool sat[200000]={0};
vector<int> E[200000],EN[200000],ED[200000];
bool vis[200000]={0};

void dfs(int i,int p)
{
  //printf("%d\n",i);
  vis[i]=1;
  for(int x=0;x<E[i].size();x++){
    int j=E[i][x];
    if(EN[i][x]==p)continue;
    if(vis[j]){
      if(!sat[i]){
	sat[i]=1;
	ans[EN[i][x]]=ED[i][x];
      }
      continue;
    }
    if(!sat[j]){
      dfs(j,EN[i][x]);
    }
    if(!sat[j]){
      sat[j]=1;
      ans[EN[i][x]]=!ED[i][x];
    }
    else if(!sat[i]){
      sat[i]=1;
      ans[EN[i][x]]=ED[i][x];
    }
  }
}



int main()
{
  int n,m;
  scanf("%d%d",&m,&n);
  static vector<int> R[200000],D[200000];
  for(int i=0;i<m;i++){
    int k;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
      int u;
      scanf("%d",&u);
      if(u>0){
	R[u-1].push_back(i);
	D[u-1].push_back(1);
      }
      else{
	R[-u-1].push_back(i);
	D[-u-1].push_back(0);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(R[i].size()==1){
      sat[R[i][0]]=1;
      ans[i]=D[i][0];
    }
    else if(R[i].size()==2){
      int a=R[i][0],b=R[i][1];
      if(D[i][0]==D[i][1]){
	sat[a]=sat[b]=1;
	ans[i]=D[i][0];
      }
      else{
	E[a].push_back(b);
	EN[a].push_back(i);
	ED[a].push_back(D[i][0]);
	E[b].push_back(a);
	EN[b].push_back(i);
	ED[b].push_back(D[i][1]);
      }
    }
  }
  bool F=1;
  for(int i=0;i<m;i++){
    if(!sat[i]){
      dfs(i,-1);
      if(!sat[i]){
	F=0;
	break;
      }
    }
  }
  if(!F){
    puts("NO");
  }
  else{
    puts("YES");
    for(int i=0;i<n;i++){
      putchar('0'+ans[i]);
    }
    putchar('\n');
  }
  return 0;
}