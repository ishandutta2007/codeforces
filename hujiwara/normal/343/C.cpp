#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
  int n,m;
  static long long x[100000],p[100000];
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%I64d",x+i);
  }
  for(int i=0;i<m;i++){
    scanf("%I64d",p+i);
  }
  long long L=-1ll,R=100000000000ll;
  while(L+1<R){
    long long M=(L+R)/2;
    int k=0;
    for(int i=0;i<n;i++){
      if(k<m){
	long long t=x[i],C=0ll;
	if(p[k]<t){
	  long long K=t-p[k];
	  C+=K;
	  if(K>M){
	    break;
	  }
	  k++;
	  while(k<m&&p[k]<=x[i]){
	    k++;
	  }
	  long long oC=C;
	  while(k<m&&oC+(p[k]-x[i])+min(K,p[k]-x[i])<=M){
	    C=oC+(p[k]-x[i])+min(K,p[k]-x[i]);
	    k++;
	  }
	}
	else{
	  while(k<m&&C+(p[k]-t)<=M){
	    C+=p[k]-t;
	    t=p[k];
	    k++;
	  }
	}
      }
    }
    if(k==m){
      R=M;
    }
    else{
      L=M;
    }
  }
  printf("%I64d\n",R);
  return 0;
}