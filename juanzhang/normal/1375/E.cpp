#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[1010],dat[1010],pos[1010];

signed main(){
  cin>>n;
  rep(i,1,n)cin>>A[i],dat[i]=A[i]=A[i]*(n+1)+i;
  sort(dat+1,dat+n+1);
  rep(i,1,n)A[i]=lower_bound(dat+1,dat+n+1,A[i])-dat;
  rep(i,1,n)pos[A[i]]=i;
  vector<pair<int,int>>ans;
  per(i,n,1){
    rep(j,A[i]+1,i)ans.push_back({pos[j],i}),swap(A[pos[j]],A[i]),swap(pos[A[pos[j]]],pos[A[i]]);
  }
  cout<<ans.size()<<endl;
  for(auto&p:ans)printf("%lld %lld\n",p.first,p.second);
  return 0;
}