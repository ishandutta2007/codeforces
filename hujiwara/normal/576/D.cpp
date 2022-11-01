#include <bits/stdc++.h>
using namespace std;

const int MN=150;

class F2matrix{
public:
  int n;
  vector<vector<long long> > M;
  F2matrix(int N,bool b){
    n=N;
    M=vector<vector<long long> >(n);
    for(int i=0;i<n;i++){
      M[i]=vector<long long>(n/60+1,0);
      for(int j=0;j<n;j++){
	M[i][j/60]|=(i==j?(long long)b:0ll)<<(j%60);
      }
    }
  }
  F2matrix(int N,bool A[MN][MN]){
    n=N;
    M=vector<vector<long long> >(n);
    for(int i=0;i<n;i++){
      M[i]=vector<long long>(n/60+1,0);
      for(int j=0;j<n;j++){
	M[i][j/60]|=(long long)A[i][j]<<(j%60);
      }
    }
  }
  void val(bool B[MN][MN]){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	B[i][j]=((M[i][j/60]>>(j%60))&1);
      }
    }
  }
};

F2matrix operator*(F2matrix A,F2matrix B)
{
  int n=A.n;
  F2matrix C(n,(bool)0);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!((A.M[i][j/60]>>(j%60))&1)){
	continue;
      }
      for(int k=0;k<=n/60;k++){
	C.M[i][k]|=B.M[j][k];
      }
    }
  }
  return C;
}

F2matrix pow(F2matrix A,long long p)
{
  int n=A.n;
  if(p==0){
    return F2matrix(n,(bool)1);
  }
  F2matrix B=pow(A,p/2);
  B=B*B;
  if(p%2==1){
    B=A*B;
  }
  return B;
}

const long long INF=10000000000ll;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  pair<long long, pair<int,int> > P[150];
  for(int i=0;i<m;i++){
    int a,b;
    long long d;
    scanf("%d%d%lld",&a,&b,&d);
    a--,b--;
    P[i]=make_pair(d,make_pair(a,b));
  }
  sort(P,P+m);
  bool A[150][150]={0};
  bool V[2][150]={0};
  bool b=0;
  V[b][0]=1;
  long long ans=INF;
  long long dis[150][150];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dis[i][j]=(i==j?0:INF);
    }
  }
  for(int t=0;t<m;t++){
    long long d=P[t].first;
    long long p=d-(t>0?P[t-1].first:0);
    F2matrix mt=pow(F2matrix(n,A),p);
    bool B[150][150];
    mt.val(B);
    /*for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	printf("%lld %d %d %d %d\n",d,i,j,A[i][j],B[i][j]);
      }
      }*/
    for(int i=0;i<n;i++){
      V[!b][i]=0;
      for(int j=0;j<n;j++){
	if(V[b][j]&&B[j][i]){
	  V[!b][i]=1;
	  break;
	}
      }
    }
    b=!b;
    int u=P[t].second.first,v=P[t].second.second;
    A[u][v]=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	dis[i][j]=min(dis[i][j],dis[i][u]+1+dis[v][j]);
      }
    }
    for(int i=0;i<n;i++){
      if(V[b][i]){
	//printf("%d %lld %lld\n",i,d,dis[i][n-1]);
	ans=min(ans,d+dis[i][n-1]);
      }
    }
  }
  if(ans==INF){
    puts("Impossible");
  }
  else{
    printf("%lld\n",ans);
  }
  return 0;
}