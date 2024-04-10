#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;

int main(){
  int n;
  set<ll>S;
  vector<ll>vec[60];
  ios::sync_with_stdio(0);
  cin>>n;
  while(n--){
    ll x,tp,t=0;cin>>x;S.insert(tp=x);
    while(~x&1)x>>=1,t++;
    vec[t].push_back(tp);
  }
  int ps=0;
  rep(i,0,59)if(vec[i].size()>vec[ps].size())ps=i;
  for(ll x:vec[ps])S.erase(x);
  cout<<S.size()<<endl;
  for(ll x:S)cout<<x<<' ';
  return 0;
}