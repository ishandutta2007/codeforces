#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  set<int> s;
  int maxbuy = 0, minsell = 1e9;
  s.insert(maxbuy);
  s.insert(minsell);
  ll ans = 1;
  while (q--) {
    string cmd;
    int price;
    cin >> cmd >> price;
    if (cmd == "ADD") {
      s.insert(price);
    } else {
      if (price < maxbuy || price > minsell) {
	ans = 0;
	break;
      }
      if (price > maxbuy && price < minsell)
	ans = ans*2%mod;
      auto it = s.find(price);
      maxbuy = *prev(it);
      minsell = *next(it);
      s.erase(it);
    }
  }
  while (s.size() && *s.begin() <= maxbuy) s.erase(*s.begin());
  while (s.size() && *s.rbegin() >= minsell) s.erase(*s.rbegin());
  ans = ans*(s.size()+1)%mod;
  cout << ans << endl;
}