#include <bits/stdc++.h>
using namespace std;
const int MN=300000;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static vector<int> s[MN];
  for(int i=0;i<n;i++){
    int k;
    scanf("%d",&k);
    s[i]=vector<int>(k);
    for(int j=0;j<k;j++){
      scanf("%d",&(s[i][j]));
      s[i][j]--;
    }
  }
  static vector<int> e[MN];
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int T=1;
  for(int i=0;i<n;i++){
    T=max(T,(int)s[i].size());
  }
  static int B[MN],C[MN];
  for(int i=0;i<T;i++){
    B[i]=-1;
  }
  for(int i=0;i<m;i++){
    C[i]=-1;
  }
  queue<int> Q;
  Q.push(0);
  static bool V[MN]={0};
  V[0]=1;
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    for(int t=0;t<s[i].size();t++){
      int p=s[i][t];
      if(C[p]!=-1){
	B[C[p]]=i;
      }
    }
    int c=0;
    for(int t=0;t<s[i].size();t++){
      int p=s[i][t];
      if(C[p]!=-1)continue;
      while(B[c]==i)c++;
      C[p]=c;
      //printf("%d %d %d\n",i,p,c);
      c++;
    }
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(!V[j]){
	V[j]=1;
	Q.push(j);
      }
    }
  }
  printf("%d\n",T);
  for(int i=0;i<m;i++){
    printf("%d%c",C[i]==-1?1:C[i]+1,i==m-1?'\n':' ');
  }
  return 0;
}