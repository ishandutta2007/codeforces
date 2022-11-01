#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int r[100000];
  for(int i=0;i<n;i++){
    scanf("%d",r+i);
  }
  static int I[100000],J[100000];
  for(int i=0;i<n;i++){
    I[i]=J[i]=-1;
  }
  for(int t=0;t<m;t++){
    int x;
    scanf("%d",&x);
    while(x--){
      int i;
      scanf("%d",&i);
      i--;
      if(I[i]==-1){
	I[i]=t;
      }
      else{
	J[i]=t;
      }
    }
  }
  vector<vector<int> > e(m),er(m);
  for(int i=0;i<n;i++){
    e[I[i]].push_back(J[i]);
    er[I[i]].push_back(r[i]);
    e[J[i]].push_back(I[i]);
    er[J[i]].push_back(r[i]);
  }
  static int B[100000]={0};
  queue<int> Q;
  bool F=0;
  for(int s=0;!F&&s<m;s++){
    if(B[s]!=0){
      continue;
    }
    Q.push(s);
    B[s]=1;
    while(!F&&!Q.empty()){
      int i=Q.front();
      Q.pop();
      for(int x=0;x<e[i].size();x++){
	int j=e[i][x],rr=er[i][x];
	int st=(rr?B[i]:3-B[i]);
	if(B[j]==0){
	  B[j]=st;
	  Q.push(j);
	}
	else if(B[j]!=st){
	  F=1;
	  break;
	}
      }
    }
  }
  puts(F?"NO":"YES");
  return 0;
}