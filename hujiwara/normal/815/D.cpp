#include <bits/stdc++.h>
using namespace std;

void updt(int x,int y,set<pair<int,int> > &S,long long &s)
{
  set<pair<int,int> >::iterator it=S.lower_bound(make_pair(x+1,0));
  if(it->second>=y){return;}
  int X=x,Y=it->second;
  it--;
  if(it->first==x&&it->second>=y){return;}
  while(it->second<=y){
    s+=(long long)(X-it->first)*(y-Y);
    X=it->first;
    Y=it->second;
    set<pair<int,int> >::iterator pre=it;
    pre--;
    S.erase(it);
    it=pre;
  }
  s+=(long long)(X-it->first)*(y-Y);
  S.insert(make_pair(x,y));
}

int main()
{
  int n,X,Y,Z;
  scanf("%d%d%d%d",&n,&X,&Y,&Z);
  static pair<int,pair<int,int> > P[500000];
  for(int i=0;i<n;i++){
    scanf("%d%d%d",&(P[i].second.first),&(P[i].second.second),&(P[i].first));
  }
  sort(P,P+n);
  set<pair<int,int> > S;
  S.insert(make_pair(0,Y+1));
  S.insert(make_pair(X+1,0));
  long long A=(long long)X*Y,s=0ll;
  for(int i=0;i<n;i++){
    updt(P[i].second.first,P[i].second.second,S,s);
    //printf("%lld\n",s);
  }
  long long ans=0ll;
  int tZ=Z;
  for(int i=n-1;i>=0;i--){
    //printf("%lld %lld %d %d\n",s,A,tZ,P[i].first);
    /*for(set<pair<int,int> >::iterator it=S.begin();it!=S.end();it++){
      printf("%d %d\n",it->first,it->second);
      }*/
    ans+=(A-s)*(tZ-P[i].first);
    tZ=P[i].first;
    updt(P[i].second.first,Y,S,s);
    updt(X,P[i].second.second,S,s);
  }
  ans+=(A-s)*tZ;
  printf("%lld\n",ans);
  return 0;
}