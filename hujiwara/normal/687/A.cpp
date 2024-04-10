#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<vector<int> > e(n);
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  static int V[100000]={0};
  bool F=0;
  for(int i=0;i<n;i++){
    if(V[i]!=0){
      continue;
    }
    queue<int> Q;
    Q.push(i);
    V[i]=1;
    while(!Q.empty()){
      int j=Q.front();
      Q.pop();
      for(int x=0;x<e[j].size();x++){
	int k=e[j][x];
	if(V[k]==0){
	  V[k]=3-V[j];
	  Q.push(k);
	}
	else if(V[k]==V[j]){
	  F=1;
	  goto FAIL;
	}
      }
    }
  }
 FAIL:
  if(F){
    printf("-1\n");
  }
  else{
    int A=0,B=0;
    for(int i=0;i<n;i++){
      if(V[i]==1){
      A++;
      }
      else{
	B++;
      }
    }
    printf("%d\n",A);
    for(int i=0;i<n;i++){
      if(V[i]==1){
	printf("%d ",i+1);
      }
    }
    putchar('\n');
    printf("%d\n",B);
    for(int i=0;i<n;i++){
      if(V[i]==2){
      printf("%d ",i+1);
      }
    }
    putchar('\n');
  }
  return 0;
}