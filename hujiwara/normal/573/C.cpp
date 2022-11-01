#include <bits/stdc++.h>
using namespace std;



int main()
{
  int n;
  static vector<int> e[100000];
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  static int B[100000]={0};
  for(int i=0;i<n;i++){
    if(e[i].size()==1){
      B[i]=1;
      int j=e[i][0],p=i;
      while(e[j].size()==2){
	B[j]=1;
	int k=e[j][0]+e[j][1]-p;
	p=j;
	j=k;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(B[i]!=0||e[i].size()>3){
      continue;
    }
    int k=0;
    for(int x=0;x<e[i].size();x++){
      if(B[e[i][x]]>0){
	k++;
      }
    }
    if(k>=2){
      B[i]=-1;
    }
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(B[i]!=0){
      continue;
    }
    int k=0;
    for(int x=0;x<e[i].size();x++){
      if(B[e[i][x]]==0){
	k++;
      }
    }
    if(k>2){
      F=1;
      break;
    }
  }
  if(F){
    puts("NO");
  }
  else{
    puts("YES");
  }
  return 0;
}