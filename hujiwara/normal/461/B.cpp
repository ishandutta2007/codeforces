#include <cstdio>
#include <vector>
using namespace std;

const long long MOD=1000000007ll;
bool p[100000];
long long A[200000],B[200000];

void dfs(int i,int pr,vector<vector<int > > &e)
{
  if(p[i]){
    A[i]=1;
    B[i]=0;
  }
  else{
    A[i]=0;
    B[i]=1;
  }
  for(int j=0;j<e[i].size();j++){
    int k=e[i][j];
    if(k==pr){
      continue;
    }
    dfs(k,i,e);
    A[i]=(A[i]*B[k]%MOD+A[i]*A[k]%MOD+B[i]*A[k]%MOD)%MOD;
    B[i]=(B[i]*B[k]%MOD+B[i]*A[k]%MOD)%MOD;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<vector<int> > e(n);
  for(int i=0;i<n-1;i++){
    int a,b=i+1;
    scanf("%d",&a);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    scanf("%d",p+i);
  }
  dfs(0,-1,e);
  printf("%I64d\n",A[0]);
  return 0;
}