#include "bits/stdc++.h"

using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mn = 2e5+10;

void solve() {
  int n;
  cin >> n;
  vector<ll>v;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(all(v));
  ll l=-1.5e6, r=1.5e6;
  auto eval = [&](ll t) {
    vector<ll> pos, neg;
    for(auto& x: v) {
      if(x>=t) pos.push_back(x-t);
      else if(x<t) neg.push_back(x-t);
    }
    reverse(all(pos));
    if(pos.size()==0){
      ll ans = 0;
      for(int i=0;i<sz(neg)-1;i++) ans += neg[i]*neg.back();
      return ans-(n-1)*t*t;
    }
    if(neg.size()==0){
      ll ans = 0;
      for(int i=0;i<sz(pos)-1;i++) ans += pos[i]*pos.back();
      return ans-(n-1)*t*t;
    }
    ll ans = neg[0]*pos[0];
    for(int i=1;i<sz(pos);i++) ans += pos[i]*neg[0];
    for(int i=1;i<sz(neg);i++) ans += neg[i]*pos[0];
    return ans-(n-1)*t*t;
  };
  while(l<r){
    ll mid = floor((l+r)*0.5);
    ll d = eval(mid+1)-eval(mid);
    if(d>0)l=mid+1;
    else r=mid;
  }
  ll lv = eval(l);
  ll d = eval(l+1)-eval(l);
  //cerr << l << " " << lv << " " << d << endl;
  if(d!=0&&(l>1.1e6||l<-1.1e6)){
    printf("INF\n");
    return;
  }
  printf("%lld\n",lv);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin>>tc;
  while(tc--){
    solve();
  }
}