#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  ll r = 0, pv;
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    if(i > 0){
      if(x < pv){
        r = max(r, pv - x);
        x = pv;
      }
    }
    pv = x;
  }
  if(r == 0){ cout << "0\n"; return; }
  int rr = 0;
  while((1LL << rr) <= r) rr++;
  cout << rr << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) solve();
}