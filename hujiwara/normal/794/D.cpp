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
    e[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    e[i].push_back(i);
    sort(e[i].begin(),e[i].end());
  }
  vector<pair<vector<int>,int> > E(n);
  for(int i=0;i<n;i++){
    E[i]=make_pair(e[i],i);
  }
  sort(E.begin(),E.end());
  int C=0;
  vector<int> F(n);
  vector<bool> H(n,0);
  for(int i=0;i<n;){
    H[E[i].second]=1;
    int t=0;
    while(i+t<n&&E[i+t].first==E[i].first){
      F[E[i+t].second]=C;
      t++;
    }
    i+=t;
    C++;
  }
  vector<vector<int> > e2(C);
  for(int i=0;i<n;i++){
    if(!H[i])continue;
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(H[j]&&i!=j){
	e2[F[i]].push_back(F[j]);
      }
    }
  }
  /*for(int i=0;i<n;i++){
    printf("%d %d\n",F[i],H[i]);
    }*/
  int s=-1;
  for(int i=0;i<C;i++){
    if(e2[i].size()<2){
      s=i;
      break;
    }
  }
  int c=0;
  vector<int> R(C);
  if(s!=-1){
    R[s]=0;
    c++;
    if(e2[s].size()==1){
      int p=s,i=e2[s][0];
      while(e2[i].size()==2){
	R[i]=c;
	c++;
	int temp=p;
	p=i;
	i=e2[i][0]+e2[i][1]-temp;
      }
      R[i]=c;
      c++;
    }
  }
  if(c==C){
    puts("YES");
    for(int i=0;i<n;i++){
      printf("%d%c",R[F[i]]+1,i<n-1?' ':'\n');
    }
  }
  else{
    puts("NO");
  }
  return 0;
}