#include <bits/stdc++.h>
using namespace std;
typedef long long cood;
typedef complex<cood> point;

namespace std{
  bool operator<(point P1,point P2)
  {
    return P1.imag()*P2.real()<P2.imag()*P1.real();
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<point> P(n);
  for(int i=0;i<n;i++){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    P[i]=point(x,y);
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    vector<pair<point,bool> > R;
    int c=0;
    for(int j=0;j<n;j++){
      if(i==j)continue;
      if(P[i].real()<P[j].real()||(P[i].real()==P[j].real()&&P[i].imag()<P[j].imag())){
	R.push_back(make_pair(P[j]-P[i],0));
	c++;
      }
      else{
	R.push_back(make_pair(P[i]-P[j],1));
      }
    }
    sort(R.begin(),R.end());
    for(int t=0;t<n-1;t++){
      if(!R[t].second){
	ans+=(long long)(c-1)*(c-2)/2*(n-c-1)*(n-c-2)/2;
	c--;
      }
      else{
	ans+=(long long)c*(c-1)/2*(n-c-2)*(n-c-3)/2;
	c++;
      }
    }
  }
  printf("%lld\n",ans/2);
  return 0;
}