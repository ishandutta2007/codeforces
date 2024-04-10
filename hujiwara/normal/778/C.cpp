#include <bits/stdc++.h>
using namespace std;

static int S[1000000][26];
int N;

int dep[400000],sz[1000000];

void dfs(int i)
{
  sz[i]=1;
  for(int c=0;c<26;c++){
    int j=S[i][c];
    if(j!=-1){
      dep[j]=dep[i]+1;
      dfs(j);
      sz[i]+=sz[j];
    }
  }
}

int mg(int i,int j)
{
  if(i==-1){
    return j;
  }
  if(j==-1){
    return i;
  }
  int ret=N;
  N++;
  sz[ret]=1;
  for(int c=0;c<26;c++){
    S[ret][c]=mg(S[i][c],S[j][c]);
    if(S[ret][c]!=-1){
      sz[ret]+=sz[S[ret][c]];
    }
  }
  return ret;
}


int main()
{
  int n;
  scanf("%d",&n);
  N=n;
  for(int i=0;i<n;i++){
    for(int c=0;c<26;c++){
      S[i][c]=-1;
    }
  }
  for(int t=0;t<n-1;t++){
    int u,v;
    char s[2];
    scanf("%d%d%s",&u,&v,s);
    u--,v--;
    int c=s[0]-'a';
    S[u][c]=v;
  }
  dep[0]=0;
  dfs(0);
  int D=0;
  for(int i=0;i<n;i++){
    D=max(D,dep[i]);
  }
  vector<vector<int> > V(D+1);
  for(int i=0;i<n;i++){
    V[dep[i]].push_back(i);
  }
  int ans=n+1,mp=-1;
  int K=0;
  for(int p=0;p<D;p++){
    int SZ=K;
    for(int t=0;t<V[p].size();t++){
      int r=V[p][t];
      N=n;
      int T=N;
      N++;
      for(int c=0;c<26;c++){
	S[T][c]=-1;
      }
      sz[T]=1;
      for(int c=0;c<26;c++){
	if(S[r][c]==-1){
	  continue;
	}
	T=mg(T,S[r][c]);
      }
      if(T!=-1){
	SZ+=sz[T];
      }
      //printf("%d %d\n",r,T==-1?0:sz[T]);
    }
    //printf("%d %d %d\n",p,SZ,K);
    if(SZ<ans){
      ans=SZ;
      mp=p+1;
    }
    K+=V[p].size();
  }
  printf("%d\n%d\n",ans,mp);
  return 0;
}