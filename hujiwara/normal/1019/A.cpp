#include <bits/stdc++.h>
using namespace std;


const long long INF=100000000000000ll;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<int> p(n);
  vector<long long> c(n);
  vector<vector<long long> > V(m);
  for(int i=0;i<n;i++){
    scanf("%d%lld",&p[i],&c[i]);
    p[i]--;
    V[p[i]].push_back(c[i]);
  }
  for(int i=0;i<m;i++){
    sort(V[i].begin(),V[i].end());
  }
  long long ans=INF;
  for(int s=1;s<=n;s++){
    long long S=0;
    int t=(int)V[0].size();
    for(int i=1;i<m;i++){
      if(V[i].size()>=s){
	for(int x=0;x<=V[i].size()-s;x++){
	  S+=V[i][x];
	  t++;
	}
      }
    }
    if(t<s){
      vector<int> v;
      for(int i=1;i<m;i++){
	for(int x=max(0,(int)V[i].size()-s+1);x<V[i].size();x++){
	  v.push_back(V[i][x]);
	}
      }
      sort(v.begin(),v.end());
      for(int x=0;x<s-t;x++){
	S+=v[x];
      }
    }
    //printf("%d %lld\n",s,S);
    ans=min(ans,S);
  }
  printf("%lld\n",ans);
  return 0;
}