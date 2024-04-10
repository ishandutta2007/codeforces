#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define x first
#define y second

pll f(int k, ll n){
  n += (1LL << k);
  ll m = n;
  m += (1LL << k);
  for(int i = 0; i < k; i += 2){
    int t = (m >> i) & 3;
    if(t == 1 || t == 2) m += (1LL << i);
    if(t == 3) m -= (2LL << i);
  }
  return pll(n, m);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    ll n;
    cin >> n;

    n--;
    int rem = n % 3;
    n = n / 3 + 1;

    int k = 0;
    while(1){
      if(n <= (1LL << k)) break;
      n -= (1LL << k);
      k += 2;
    }

    pll ans = f(k, n - 1);
    if(rem == 0) cout << ans.x << '\n';
    else if(rem == 1) cout << ans.y << '\n';
    else cout << (ans.x ^ ans.y) << '\n';
  }
}