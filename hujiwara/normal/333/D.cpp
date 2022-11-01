#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int a[1000][1000];
  static pair<int,pair<int,int> > P[1000000];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",a[i]+j);
      P[i*m+j].first=a[i][j];
      P[i*m+j].second.first=i;
      P[i*m+j].second.second=j;
    }
  }
  sort(P,P+n*m);
  static bool G[1000][1000]={0};
  vector<int> v[1000];
  for(int t=n*m-1;t>=0;t--){
    int i=P[t].second.first,j=P[t].second.second;
    for(int k=0;k<v[i].size();k++){
      int l=v[i][k];
      if(G[j][l]){
	printf("%d\n",P[t].first);
	goto END;
      }
      G[j][l]=1;
      G[l][j]=1;
    }
    v[i].push_back(j);
  }
 END:
  return 0;
}