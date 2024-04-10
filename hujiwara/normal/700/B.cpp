#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > e;
bool U[200000];
int S[200000];
int n,k;
long long M;

void dfs(int i,int p)
{
  S[i]=U[i];
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p){
      continue;
    }
    dfs(j,i);
    S[i]+=S[j];
    M+=min(2*k-S[j],S[j]);
  }
}
int main()
{
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    U[i]=0;
  }
  for(int i=0;i<2*k;i++){
    int a;
    scanf("%d",&a);
    a--;
    U[a]=1;
  }
  e=vector<vector<int> >(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  M=0ll;
  dfs(0,-1);
  printf("%I64d\n",M);
  return 0;
}