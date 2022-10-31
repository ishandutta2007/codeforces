#include <bits/stdc++.h>
using namespace std;
const long long INF=1000000000000ll;

int main()
{
  int n,m,K;
  scanf("%d%d%d",&n,&m,&K);
  K++;
  vector<vector<pair<int,int> > > af(n),df(n);
  vector<pair<int,int> > ev(m);
  for(int t=0;t<m;t++){
    int d,a,b,c;
    scanf("%d%d%d%d",&d,&a,&b,&c);
    if(b==0){
      a--;
      af[a].push_back(make_pair(d,c));
      ev[t]=make_pair(d,-a-1);
    }
    else if(a==0){
      b--;
      df[b].push_back(make_pair(d,c));
      ev[t]=make_pair(d-K,b+1);
    }
  }
  sort(ev.begin(),ev.end());
  vector<vector<long long> > mc1(n),mc2(n);
  for(int i=0;i<n;i++){
    sort(af[i].begin(),af[i].end());
    mc1[i]=vector<long long>(af[i].size()+1);
    mc1[i][0]=INF;
    for(int t=0;t<af[i].size();t++){
      mc1[i][t+1]=min(mc1[i][t],(long long)af[i][t].second);
    }
    sort(df[i].begin(),df[i].end());
    mc2[i]=vector<long long>(df[i].size()+1);
    mc2[i][df[i].size()]=INF;
    for(int t=df[i].size()-1;t>=0;t--){
      mc2[i][t]=min(mc2[i][t+1],(long long)df[i][t].second);
    }
  }
  vector<int> f1(n,0),f2(n,0);
  long long S=0ll;
  for(int i=0;i<n;i++)S+=mc1[i][0]+mc2[i][0];
  long long ans=S;
  for(int t=0;t<m;t++){
    int q=ev[t].second;
    //printf("%d %d\n",ev[t].first,ev[t].second);
    if(q<0){
      int i=-q-1;
      S+=mc1[i][f1[i]+1]-mc1[i][f1[i]];
      f1[i]++;
    }
    else{
      int i=q-1;
      S+=mc2[i][f2[i]+1]-mc2[i][f2[i]];
      f2[i]++;
    }
    ans=min(ans,S);
  }
  printf("%lld\n",ans<INF?ans:-1);
  return 0;
}