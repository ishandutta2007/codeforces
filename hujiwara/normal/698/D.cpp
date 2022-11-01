#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
const double EPS=1e-8;

double ip(point P1,point P2)
{
  return real((conj(P1)*P2));
}

double op(point P1,point P2)
{
  return imag((conj(P1)*P2));
}

double ccw(point P0,point P1,point P2)
{
  return op(P1-P0,P2-P0);
}

bool line_in(point P1,point P2,point P3)
{
  bool ret;
  if(abs(ccw(P1,P2,P3))>EPS){
    ret=0;
  }
  else{
    double d=ip(P2-P1,P3-P1);
    ret=(EPS<d&&d<ip(P2-P1,P2-P1)-EPS);
  }
  return ret;
}

int main()
{
  int K,n;
  scanf("%d%d",&K,&n);
  point A[7],M[1000];
  for(int i=0;i<K;i++){
    double x,y;
    scanf("%lf%lf",&x,&y);
    A[i]=point(x,y);
  }
  for(int j=0;j<n;j++){
    double x,y;
    scanf("%lf%lf",&x,&y);
    M[j]=point(x,y);
  }
  vector<int> e[7][1000];
  for(int i=0;i<K;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
	if(k!=j&&line_in(A[i],M[j],M[k])){
	  e[i][j].push_back(k);
	}
      }
    }
  }
  int C=0;
  int G[1000]={0};
  int T=0;
  for(int t=0;t<n;t++){
    int p[7];
    for(int i=0;i<K;i++){
      p[i]=i;
    }
    do{
      T++;
      stack<int> S;
      S.push(t);
      for(int i=0;i<K&&!S.empty();i++){
	int j=S.top();
	S.pop();
	for(int x=0;x<e[p[i]][j].size()&&S.size()<K-i;x++){
	  int k=e[p[i]][j][x];
	  if(G[k]!=T){
	    G[k]=T;
	    S.push(k);
	  }
	}
	if(S.size()>=K-i){
	  break;
	}
      }
      if(S.empty()){
	C++;
	break;
      }
    }while(next_permutation(p,p+K));
  }
  printf("%d\n",C);
  return 0;
}