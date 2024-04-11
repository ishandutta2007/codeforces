//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int INF = 1e9+7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  // [koniec, poczatek]
  set <pii> S;
  S.emplace(1, n);
  int good = n;
  auto cut = [&](int x) {
    if(x > n) return;
    auto it = S.lower_bound(make_pair(x, -INF));
    if(get<0>(*it) == x) return;
    it = prev(it);
    auto e = *it;
    S.erase(it);
    S.emplace(e.x, (x-1) * (e.y > 0 ? 1 : -1));
    S.emplace(x, e.y);
  };
  while(q--) {
    int a, b, k;
    cin >> a >> b >> k;
    k--;
    cut(a);
    cut(b+1);
    auto it = S.lower_bound(make_pair(a, -INF));
    auto jt = S.upper_bound(make_pair(b, INF));
    for(auto kt = it; kt != jt; kt++) {
      if(kt->y > 0)
        good -= abs(kt->y) - kt->x + 1;
    }
    S.erase(it, jt);
    S.emplace(a, (k == 0 ? -b : b));
    if(k == 1) good += b-a+1;
    cout << good << "\n";
  }
  return 0;
}