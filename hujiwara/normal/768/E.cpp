#include <bits/stdc++.h>
using namespace std;

map<pair<int,long long>,int> M;

int rec(int a,long long I)
{
  if(M.find(make_pair(a,I))!=M.end()){
    return M[make_pair(a,I)];
  }
  bool D[100]={0};
  for(int i=1;i<=a;i++){
    if(!((I>>i)&1)){
      D[rec(a-i,(I|(1ll<<i)))&((1ll<<(a-i+1))-1ll)]=1;
    }
  }
  int C=0;
  while(D[C]){
    C++;
  }
  M[make_pair(a,I)]=C;
  return C;
}

int main()
{
  int G[100];
  for(int i=0;i<=60;i++){
    G[i]=rec(i,0ll);
  }
  int n;
  scanf("%d",&n);
  int g=0;
  for(int i=0;i<n;i++){
    int s;
    scanf("%d",&s);
    g^=G[s];
  }
  puts(g==0?"YES":"NO");
  return 0;
}