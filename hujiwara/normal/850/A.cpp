#include <bits/stdc++.h>
using namespace std;



int main()
{
  int n;
  int X[1000][6];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    for(int t=0;t<5;t++){
      scanf("%d",X[i]+t);
    }
  }
  vector<int> ans;
  if(n<=12){
    for(int i=0;i<n;i++){
      int F=0;
      for(int j=0;j<n;j++){
	for(int k=j+1;k<n;k++){
	  if(i==j||i==k)continue;
	  int T=0;
	  for(int t=0;t<5;t++){
	    T+=(X[j][t]-X[i][t])*(X[k][t]-X[i][t]);
	  }
	  if(T>0){
	    F=1;
	  }
	}
      }
      if(!F){
	ans.push_back(i);
      }
    }
  }
  printf("%d\n",(int)ans.size());
  for(int t=0;t<ans.size();t++){
    printf("%d\n",ans[t]+1);
  }
  return 0;
}