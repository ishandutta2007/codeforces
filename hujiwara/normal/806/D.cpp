#include <bits/stdc++.h>
using namespace std;

typedef long long dis;
void dijkstra2(vector<dis> &d,const vector<vector<dis> > D)
{
  int n=d.size();
  vector<bool> V(n,0);
  for(int t=0;t<n;t++){
    int i=-1;
    for(int k=0;k<n;k++){
      if(!V[k]&&(i==-1||d[i]>d[k]))i=k;
    }
    V[i]=1;
    for(int j=0;j<n;j++){
      d[j]=min(d[j],d[i]+D[i][j]);
    }
  }
}

const long long INF=10000000000ll;

int main()
{
  int n;
  scanf("%d",&n);
  vector<vector<long long> > D(n,vector<long long>(n));
  long long R=INF;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      scanf("%lld",&(D[i][j]));
      D[j][i]=D[i][j];
      R=min(R,D[i][j]);
    }
    D[i][i]=INF;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      D[i][j]-=R;
    }
  }
  vector<long long> d(n);
  for(int i=0;i<n;i++){
    d[i]=INF;
    for(int j=0;j<n;j++){
      d[i]=min(d[i],D[i][j]);
    }
    d[i]*=2;
  }
  dijkstra2(d,D);
  for(int i=0;i<n;i++){
    printf("%lld\n",d[i]+(n-1)*R);
  }
  return 0;
}