#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int d[100000]={0};
  static vector<int> e[100000];
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    d[a]++;
    d[b]++;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  static int K[100001]={0};
  for(int i=0;i<n;i++){
    K[d[i]]++;
  }
  queue<int> Q;
  static bool v[100000]={0};
  Q.push(0);
  v[0]=1;
  int C=1;
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    for(int j=0;j<e[i].size();j++){
      int k=e[i][j];
      if(!v[k]){
	Q.push(k);
	v[k]=1;
	C++;
      }
    }
  }
  if(C==n&&m==n-1&&K[1]==2&&K[2]==n-2){
    puts("bus topology");
  }
  else if(C==n&&m==n&&K[2]==n){
    puts("ring topology");
  }
  else if(C==n&&K[1]==n-1&&K[n-1]==1){
    puts("star topology");
  }
  else{
    puts("unknown topology");
  }
  return 0;
}