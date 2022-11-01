#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> pt;

const long long EPS=0ll;

namespace std{
  bool operator<(pt P1,pt P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()<P2.real():P1.imag()<P2.imag();
  }
  bool operator>(pt P1,pt P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()>P2.real():P1.imag()>P2.imag();
  } 
}

long long ep(pt P1,pt P2){return imag((conj(P1)*P2));}

struct ang{
  long long x,y;
};

bool operator<(ang p,ang q)
{
  return p.y*q.x<q.y*p.x;
}

vector<pt> P;

int main()
{
  int n;
  long long S;
  scanf("%d%lld",&n,&S);
  P=vector<pt>(n);
  for(int  i=0;i<n;i++){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    P[i]=pt(x,y);
  }
  sort(P.begin(),P.end());
  vector<int> order(n),rorder(n);
  for(int i=0;i<n;i++){
    order[i]=i;
    rorder[i]=i;
  }
  vector<pair<ang,pair<int,int> > > V;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      ang v;
      v.x=P[j].real()-P[i].real();
      v.y=P[j].imag()-P[i].imag();
      V.push_back(make_pair(v,make_pair(i,j)));
    }
  }
  sort(V.begin(),V.end());
  bool F=0;
  int ai,aj,ak;
  for(int t=V.size()-1;t>=0;t--){
    int i=V[t].second.first,j=V[t].second.second,k;
    //printf("%d %d\n",i,j);
    int L=0,R=n;
    while(L<R){
      int k=order[(L+R)/2];
      long long s=ep(P[j]-P[i],P[k]-P[i]);
      if(s==2*S){
	ai=i,aj=j,ak=k;
	F=1;
	break;
      }
      else if(s>2*S){
	L=(L+R)/2+1;
      }
      else{
	R=(L+R)/2;
      }
    }
    if(F)break;
    L=0,R=n;
    while(L<R){
      int k=order[(L+R)/2];
      long long s=ep(P[j]-P[i],P[k]-P[i]);
      if(s==-2*S){
	ai=i,aj=j,ak=k;
	F=1;
	break;
      }
      else if(s>-2*S){
	L=(L+R)/2+1;
      }
      else{
	R=(L+R)/2;
      }
    }
    if(F)break;
    swap(rorder[i],rorder[j]);
    order[rorder[i]]=i;
    order[rorder[j]]=j;
  }
  if(F){
    puts("Yes");
    //printf("%d %d %d\n",ai,aj,ak);
    printf("%lld %lld\n%lld %lld\n%lld %lld\n",P[ai].real(),P[ai].imag(),
	   P[aj].real(),P[aj].imag(),P[ak].real(),P[ak].imag());
  }
  else{
    puts("No");
  }
  return 0;
}