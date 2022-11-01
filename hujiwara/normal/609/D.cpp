#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  int n,m,k;
  ll s;
  scanf("%d%d%d%I64d",&n,&m,&k,&s);
  static ll a[200000],b[200000];
  for(int i=0;i<n;i++){
    scanf("%I64d",a+i);
  }
  for(int i=0;i<n;i++){
    scanf("%I64d",b+i);
  }
  static int t[200000];
  static ll c[200000];
  for(int i=0;i<m;i++){
    scanf("%d%I64d",t+i,c+i);
  }
  static ll ma[200000],mb[200000];
  ma[0]=a[0];
  mb[0]=b[0];
  for(int i=1;i<n;i++){
    ma[i]=min(ma[i-1],a[i]);
    mb[i]=min(mb[i-1],b[i]);
  }
  int L=0,R=n+1;
  while(L+1<R){
    int M=(L+R)/2;
    static ll C[200000];
    for(int i=0;i<m;i++){
      if(t[i]==1){
	C[i]=c[i]*ma[M-1];
      }
      else if(t[i]==2){
	C[i]=c[i]*mb[M-1];
      }
    }
    sort(C,C+m);
    ll am=0ll;
    for(int i=0;i<k;i++){
      am+=C[i];
    }
    if(am<=s){
      R=M;
    }
    else{
      L=M;
    }
  }
  if(R==n+1){
    printf("%d\n",-1);
  }
  else{
    printf("%d\n",R);
    int ad,bd;
    for(int i=0;i<R;i++){
      if(a[i]==ma[R-1]){
	ad=i;
	break;
      }
    }
    for(int i=0;i<R;i++){
      if(b[i]==mb[R-1]){
	bd=i;
	break;
      }
    }
    static pair<ll,int> P[200000];
    for(int i=0;i<m;i++){
      if(t[i]==1){
	P[i].first=c[i]*ma[R-1];
      }
      else if(t[i]==2){
	P[i].first=c[i]*mb[R-1];
      }
      P[i].second=i;
    }
    sort(P,P+m);
    for(int i=0;i<k;i++){
      int j=P[i].second;
      printf("%d %d\n",j+1,t[j]==1?ad+1:bd+1);
    }
  }
  return 0;
}