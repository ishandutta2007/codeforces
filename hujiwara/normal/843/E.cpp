#include <bits/stdc++.h>
using namespace std;

typedef int flow_type;
const int INF=100000;

vector<vector<int> > e;
vector<vector<flow_type> > c;

void add(int i,int j,flow_type v)
{
  e[i].push_back(j);
  c[i].push_back(v);
}

const int VSIZE=200,ESIZE=4000;

flow_type MF(int s,int t,bool *cut)
{
  int n=e.size();
  flow_type F[ESIZE]={0},C[ESIZE];
  int K=0;
  vector<vector<int> > fk(n),be(n),bfk(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<e[i].size();j++){
      int k=e[i][j];
      C[K]=c[i][j];
      fk[i].push_back(K);
      be[k].push_back(i);
      bfk[k].push_back(K);
      K++;
    }
  }
  flow_type fl=0ll;
  while(1){
    int dis[VSIZE]={0};
    queue<int> Q;
    Q.push(s);
    dis[s]=1;
    while(!Q.empty()){
      int i=Q.front();
      Q.pop();
      for(int j=0;j<e[i].size();j++){
	if(F[fk[i][j]]==C[fk[i][j]]){
	  continue;
	}
	int k=e[i][j];
	if(!dis[k]){
	  Q.push(k);
	  dis[k]=dis[i]+1;
	}
      }
      for(int j=0;j<be[i].size();j++){
	if(F[bfk[i][j]]==0){
	  continue;
	}
	int k=be[i][j];
	if(!dis[k]){
	  Q.push(k);
	  dis[k]=dis[i]+1;
	}
      }
    }
    if(!dis[t]){
      for(int i=0;i<n;i++){
	cut[i]=(dis[i]>0);
      }
      break;
    }
    while(1){
      int B[VSIZE],FF[VSIZE];
      for(int i=0;i<n;i++){
	B[i]=-1;
      }
      stack<int> Q;
      Q.push(s);
      while(!Q.empty()){
	int i=Q.top();
	Q.pop();
	if(i==t){
	  break;
	}
	for(int j=0;j<e[i].size();j++){
	  int k=e[i][j];
	  if(dis[k]!=dis[i]+1||F[fk[i][j]]==C[fk[i][j]]){
	    continue;
	  }
	  if(B[k]==-1){
	    Q.push(k);
	    B[k]=i;
	    FF[k]=fk[i][j]+1;
	  }
	}
	for(int j=0;j<be[i].size();j++){
	  int k=be[i][j];
	  if(dis[k]!=dis[i]+1||F[bfk[i][j]]==0){
	    continue;
	  }
	  if(B[k]==-1){
	    Q.push(k);
	    B[k]=i;
	    FF[k]=-bfk[i][j]-1;
	  }
	}
      }
      if(B[t]==-1){
	break;
      }
      flow_type M=INF;
      for(int i=t;i!=s;i=B[i]){
	int J=FF[i];
	if(J>0){
	  int j=J-1;
	  M=min(M,C[j]-F[j]);
	}
	else{
	  int j=-J-1;
	  M=min(M,F[j]);
	}
      }
      fl+=M;
      for(int i=t;i!=s;i=B[i]){
	int J=FF[i];
	if(J>0){
	  int j=J-1;
	  F[j]+=M;
	}
	else{
	  int j=-J-1;
	  F[j]-=M;
	}
      }
    }
  }
  return fl;
}

vector<int> F,S;
vector<bool> vis;


vector<vector<int> > E,id;

void DFS(int i,int t)
{
  vis[i]=1;
  S[i]=E[i].size();
  for(int x=0;x<E[i].size();x++){
    int j=E[i][x],p=id[i][x];
    if(j==t||vis[j]){
      continue;
    }
    else{
      DFS(j,t);
      S[i]+=S[j];
      F[p]+=S[j];
    }
  }
}

int main()
{
  int n,m,s,t;
  scanf("%d%d%d%d",&n,&m,&s,&t);
  s--,t--;
  e=vector<vector<int> >(n);
  c=vector<vector<int> >(n);
  vector<int> u(m),v(m),g(m);
  for(int x=0;x<m;x++){
    scanf("%d%d%d",&(u[x]),&(v[x]),&(g[x]));
    u[x]--,v[x]--;
    if(g[x]){
      add(v[x],u[x],INF);
      add(u[x],v[x],1);
    }
    else{
      add(u[x],v[x],INF);
    }
  }
  bool cut[100];
  int k=MF(s,t,cut);
  F=vector<int>(m,0);
  E=vector<vector<int> >(n);
  id=vector<vector<int> >(n);
  for(int x=0;x<m;x++){
    if(g[x]){
      E[u[x]].push_back(v[x]);
      id[u[x]].push_back(x);
      F[x]++;
    }
  }
  vis=vector<bool>(n,0);
  S=vector<int>(n,0);
  DFS(s,t);
  E=vector<vector<int> >(n);
  id=vector<vector<int> >(n);
  for(int x=0;x<m;x++){
    if(g[x]){
      E[v[x]].push_back(u[x]);
      id[v[x]].push_back(x);
    }
  }
  vis=vector<bool>(n,0);
  S=vector<int>(n,0);
  DFS(t,s);
  printf("%d\n",k);
  for(int x=0;x<m;x++){
    printf("%d %d\n",F[x],F[x]+(cut[u[x]]&&!cut[v[x]]?0:1));
  }
  return 0;
}