#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(a[i]==1||b[i]==1){
      F=1;
    }
  }
  if(F){
    puts("-1");
  }
  else{
    double L=0.,R=2e9;
    while(R-L>1e-7){
      double M=(L+R)/2.;
      bool F=0;
      double f=M;
      for(int i=0;i<n;i++){
	f-=(m+f)/a[i];
	if(f<0){
	  F=1;
	  break;
	}
	f-=(m+f)/b[(i+1)%n];
	if(f<0){
	  F=1;
	  break;
	}
      }
      if(F){
	L=M;
      }
      else{
	R=M;
      }
    }
    printf("%.8lf\n",R);
  }
  return 0;
}