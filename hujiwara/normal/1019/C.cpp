#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<vector<int> > e(n);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
  }
  vector<int> order(n,-1);
  for(int i=0;i<n;i++){
    if(order[i]!=-1)continue;
    order[i]=i;
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(order[j]==-1){
	order[j]=i;
      }
    }
  }
  vector<int> ct(n,0),ans;
  for(int i=n-1;i>=0;i--){
    if(order[i]==i&&ct[i]==0){
      ans.push_back(i);
      for(int x=0;x<e[i].size();x++){
	ct[e[i][x]]++;
      }
    }
  }
  int k=ans.size();
  printf("%d\n",k);
  for(int t=k-1;t>=0;t--){
    printf("%d%c",ans[t]+1,t>0?' ':'\n');
  }
  return 0;
}