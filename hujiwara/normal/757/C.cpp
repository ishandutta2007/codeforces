#include <bits/stdc++.h>
using namespace std;

struct vec{
  vector<pair<int,int> > V;
};

bool operator<(vec v1,vec v2)
{
  for(int i=0;i<v1.V.size()&&i<v2.V.size();i++){
    if(v1.V[i]!=v2.V[i]){
      return v1.V[i]<v2.V[i];
    }
  }
  return v1.V.size()<v2.V.size();
}

bool operator==(vec v1,vec v2)
{
  for(int i=0;i<v1.V.size()&&i<v2.V.size();i++){
    if(v1.V[i]!=v2.V[i]){
      return 0;
    }
  }
  return v1.V.size()==v2.V.size();
}
const long long mod=1000000007ll;
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static vec T[1000000];
  for(int i=0;i<m;i++){
    T[i].V=vector<pair<int,int> >(0);
  }
  static int a[100000];
  for(int q=0;q<n;q++){
    int g;
    scanf("%d",&g);
    for(int i=0;i<g;i++){
      scanf("%d",a+i);
      a[i]--;
    }
    sort(a,a+g);
    for(int i=0;i<g;){
      int t=1;
      while(i+t<g&&a[i+t]==a[i]){
	t++;
      }
      T[a[i]].V.push_back(make_pair(q,t));
      i+=t;
    }
  }
  sort(T,T+m);
  static long long F[1000010];
  F[0]=1ll;
  for(int i=1;i<=m;i++){
    F[i]=F[i-1]*i%mod;
  }
  long long ans=1;
  for(int i=0;i<m;){
    int t=1;
    while(i+t<m&&T[i+t]==T[i]){
      t++;
    }
    ans*=F[t];
    ans%=mod;
    i+=t;
  }
  printf("%lld\n",ans);
  return 0;
}