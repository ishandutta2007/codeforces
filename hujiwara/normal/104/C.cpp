#include <cstdio>
#include <vector>
using namespace std;

int dfs(int a,bool v[100],vector<vector<int> > &e)
{
  int c=0;
  if(!v[a]){
    v[a]=1;
    c=1;
    for(int j=0;j<e[a].size();j++){
      c+=dfs(e[a][j],v,e);
    }
  }
  return c;
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<vector<int> > e(n);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  bool v[100]={0};
  if(n==m&&n==dfs(0,v,e)){
    puts("FHTAGN!");
  }
  else{
    puts("NO");
  }
  return 0;
}