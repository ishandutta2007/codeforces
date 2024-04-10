#include <bits/stdc++.h>
using namespace std;


const long long INF=1000000000000000000ll;

template<class T> class matrix{
public:
  int n;
  vector<vector<T> > M;
  matrix(){}
  matrix(int N){
    n=N;
    M=vector<vector<T> >(n);
    for(int i=0;i<n;i++){
      M[i]=vector<T>(n);
      for(int j=0;j<n;j++){
	M[i][j]=(i==j?0:INF);
      }
    }
  }
  matrix<T> operator*(matrix<T> B)
  {
    assert(B.n==n);
    matrix<T> C(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	C.M[i][j]=INF;
	for(int k=0;k<n;k++){
	  C.M[i][j]=min(C.M[i][j],M[i][k]+B.M[k][j]);
	}
      }
    }
    return C;
  }
  matrix<T> pow(long long a)
  {
    matrix<T> ret;
    if(a==0){
      ret=matrix<T>(n);
    }
    else{
      ret=pow(a/2);
      ret=ret*ret;
      if(a%2==1){
	ret=ret*(*this);
      }
    }
    return ret;
  }
};

int x,k,n,q;
vector<int> VI;
int N;
long long c[8];

matrix<long long> mat(long long w)
{
  matrix<long long> A(N);
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)A.M[i][j]=INF;
  for(int i=0;i<N;i++){
    int I=VI[i];
    if(I&1){
      int J=(I>>1);
      for(int y=0;y<k;y++){
	if(!((J>>y)&1)){
	  int j=lower_bound(VI.begin(),VI.end(),J|(1<<y))-VI.begin();
	  A.M[i][j]=c[y]+w;
	}
      }
    }
    else{
      int J=(I>>1);
      int j=lower_bound(VI.begin(),VI.end(),J)-VI.begin();
      A.M[i][j]=0;
    }
  }
  return A;
}  

int main()
{
  scanf("%d%d%d%d",&x,&k,&n,&q);
  for(int I=0;I<(1<<k);I++){
    int y=0;
    for(int t=0;t<k;t++){
      if((I>>t)&1)y++;
    }
    if(y==x){
      VI.push_back(I);
    }
  }
  N=VI.size();
  for(int y=0;y<k;y++){
    scanf("%lld",c+y);
  }
  matrix<long long> A=mat(0);
  /*for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%lld ",A.M[i][j]);
    }
    putchar('\n');
    }*/
  pair<int,long long> P[25];
  for(int i=0;i<q;i++){
    scanf("%d%lld",&(P[i].first),&(P[i].second));
    P[i].first--;
  }
  sort(P,P+q);
  matrix<long long> Q(N);
  int m=0;
  long long ans=0ll;
  for(int v=0;v<q;v++){
    int mm=P[v].first;
    if(n-x>mm){
      Q=Q*(A.pow(mm-m));
      matrix<long long> A2=mat(P[v].second);
      Q=Q*A2;
      m=mm+1;
    }
    else{
      ans+=P[v].second;
    }
  }
  Q=Q*(A.pow(n-x-m));
  printf("%lld\n",Q.M[0][0]+ans);
}