#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static long long x[100000],y[100000];
  for(int i=0;i<n;i++){
    long long x1,x2,y1,y2;
    scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
    x[i]=x1+x2;
    y[i]=y1+y2;
  }
  static long long X[100000],Y[100000];
  for(int i=0;i<n;i++){
    X[i]=x[i];
    Y[i]=y[i];
  }
  sort(X,X+n);
  sort(Y,Y+n);
  vector<int> v;
  for(int i=0;i<n;i++){
    if(x[i]<X[k]||X[n-k-1]<x[i]||y[i]<Y[k]||Y[n-k-1]<y[i]){
      v.push_back(i);
    }
  }
  long long ans=-1ll;
  for(int i=0;i<=k;i++){
    for(int j=max(i,n-k-1);j<n;j++){
      for(int p=0;p<=k;p++){
	for(int q=max(p,n-k-1);q<n;q++){
	  int c=0;
	  for(int t=0;t<v.size();t++){
	    int l=v[t];
	    if(!(X[i]<=x[l]&&x[l]<=X[j]&&Y[p]<=y[l]&&y[l]<=Y[q])){
	      c++;
	    }
	  }
	  if(c>k){
	    continue;
	  }
	  long long a=(X[j]-X[i]==0?1:(X[j]-X[i]+1)/2);
	  long long b=(Y[q]-Y[p]==0?1:(Y[q]-Y[p]+1)/2);
	  if(ans==-1||ans>a*b){
	    ans=a*b;
	  }
	}
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}