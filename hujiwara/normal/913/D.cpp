#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long T;
  scanf("%d%lld",&n,&T);
  static int a[300000],t[300000];
  for(int i=0;i<n;i++){
    scanf("%d%d",a+i,t+i);
  }
  int L=0,R=n+1;
  vector<int> ans;
  while(L+1<R){
    int k=(L+R)/2;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
      if(a[i]>=k){
	v.push_back(make_pair(t[i],i));
      }
    }
    sort(v.begin(),v.end());
    int N=v.size();
    if(N<k){
      R=k;
      continue;
    }
    long long T2=0ll;
    for(int i=0;i<k;i++)T2+=v[i].first;
    if(T2<=T){
      vector<int> tp;
      for(int i=0;i<k;i++)tp.push_back(v[i].second);
      ans=tp;
      L=k;
    }
    else{
      R=k;
    }
  }
  printf("%d\n%d\n",L,L);
  for(int i=0;i<L;i++){
    printf("%d%c",ans[i]+1,i==L-1?'\n':' ');
  }
  return 0;
}