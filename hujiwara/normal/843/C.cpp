#include <bits/stdc++.h>
using namespace std;
int sub[200000];

void dfs(int i,int p,vector<vector<int> > &e)
{
  sub[i]=1;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p){
      continue;
    }
    dfs(j,i,e);
    sub[i]+=sub[j];
  }
}

pair<int,int> cent(vector<vector<int> > &e)
{
  dfs(0,-1,e);
  int a=0,b,p=-1,n=sub[0];
  while(1){
    int S=0,q=-1;
    for(int x=0;x<e[a].size();x++){
      int j=e[a][x];
      if(j==p){
	continue;
      }
      if(S<sub[j]){
	S=sub[j];
	q=j;
      }
    }
    if(S<=n/2){
      if(2*S==n){
	b=q;
      }
      else{
	b=-1;
      }
      break;
    }
    p=a;
    a=q;
  }
  return make_pair(a,b);
}

vector<int> ans1,ans2,ans3;

void dfs2(int i,int p,int c,vector<vector<int> > &e,vector<int> &v)
{
  int q=c;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    ans1.push_back(q),ans2.push_back(i),ans3.push_back(j);
    dfs2(j,i,q,e,v);
    q=j;
  }
  v.push_back(i);
}
  

void sol(int s,int c,vector<vector<int> > &e)
{
  vector<int> v;
  v.push_back(c);
  dfs2(s,c,c,e,v);
  int k=v.size();
  for(int t=k-4;t>=0;t--){
    ans1.push_back(v[t]),ans2.push_back(v[t+1]),ans3.push_back(v[k-2]);
  }
}


int main()
{
  int n;
  scanf("%d",&n);
  vector<vector<int> > e(n);
  for(int t=0;t<n-1;t++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  pair<int,int> ct=cent(e);
  int c1=ct.first,c2=ct.second;
  for(int x=0;x<e[c1].size();x++){
    int i=e[c1][x];
    if(i==c2)continue;
    sol(i,c1,e);
  }
  if(c2!=-1){
    for(int x=0;x<e[c2].size();x++){
      int i=e[c2][x];
      if(i==c1)continue;
      sol(i,c2,e);
    }
  }
  int K=ans1.size();
  printf("%d\n",K);
  for(int i=0;i<K;i++){
    printf("%d %d %d\n",ans1[i]+1,ans2[i]+1,ans3[i]+1);
  }
  return 0;
}