#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static vector<int> e[1000000];
  static bool L[1000000]={0};
  int lp=0;
  for(int t=0;t<m;t++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    if(a!=b){
      e[a].push_back(b);
      e[b].push_back(a);
    }
    else{
      lp++;
    }
    L[a]=L[b]=1;
  }
  queue<int> Q;
  static bool V[1000000]={0};
  for(int i=0;i<n;i++){
    if(L[i]){
      V[i]=1;
      Q.push(i);
      break;
    }
  }
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(!V[j]){
	V[j]=1;
	Q.push(j);
      }
    }
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(L[i]&&!V[i]){
      F=1;
      break;
    }
  }
  long long ans=0ll;
  if(!F){
    for(int i=0;i<n;i++){
      int d=e[i].size();
      ans+=(long long)d*(d-1ll)/2ll;
    }
    ans+=(long long)lp*(m-lp)+(long long)lp*(lp-1ll)/2ll;
  }
  printf("%lld\n",ans);
  return 0;
}