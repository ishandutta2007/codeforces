#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}

set<pair<long long,pair<int,int> > > S;
map<pair<int,int>,int> M;

void M_minus(int x,int y,int q)
{
  int g=gcd(x,y);
  x/=g,y/=g;
  auto it=M.find(make_pair(x,y));
  if(it==M.end()){
    M[make_pair(x,y)]=q;
  }
  else{
    it->second+=q;
  }
}


int main()
{
  int q;
  scanf("%d",&q);
  for(int T=0;T<q;T++){
    int t,x,y;
    scanf("%d%d%d",&t,&x,&y);
    if(t==1){
      M_minus(x,y,1);
      long long L=(long long)x*x+(long long)y*y;
      for(auto it=S.lower_bound(make_pair(L,make_pair(0,0)));it!=S.end()&&it->first==L;it++){
	M_minus(x+it->second.first,y+it->second.second,2);
      }
      S.insert(make_pair(L,make_pair(x,y)));
    }
    else if(t==2){
      long long L=(long long)x*x+(long long)y*y;
      S.erase(make_pair(L,make_pair(x,y)));
      M_minus(x,y,-1);
      for(auto it=S.lower_bound(make_pair(L,make_pair(0,0)));it!=S.end()&&it->first==L;it++){
	M_minus(x+it->second.first,y+it->second.second,-2);
      }
    }
    else{
      int g=gcd(x,y);
      x/=g,y/=g;
      auto it=M.find(make_pair(x,y));
      printf("%d\n",(int)S.size()-(it==M.end()?0:it->second));
    }
  }
  return 0;
}