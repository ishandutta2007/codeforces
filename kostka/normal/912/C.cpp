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

int damage;

struct hero {
  int max_health, start_health, regen;
  vector <pair <int, int> > changes;
  hero(int mh = 0, int sh = 0, int r = 0) : max_health(mh), start_health(sh), regen(r) { }
  vector <pair <int, int> > killable_periods() {
    sort(changes.begin(), changes.end());
    changes.emplace_back(INT_MAX, INT_MAX);
    vector <pair <int, int> > ret;
    int cur_health = start_health;
    int ttt = 0;
    for(int i=0; i<SZ(changes); i++) {
      if(cur_health <= damage) {
        long long eee = ((regen == 0) ? 2e9 : floor(1.0 * (damage - cur_health) / regen));
        if(eee >= 0) ret.emplace_back(ttt, min(ttt+eee, (ll)changes[i].first-1));
      }
      tie(ttt, cur_health) = changes[i];
     }
     return ret;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, bounty, increase;
  cin >> n >> m >> bounty >> increase >> damage;
  vector <hero> H;
  for(int i=0; i<n; i++) {
    int max_health, start_health, regen;
    cin >> max_health >> start_health >> regen;
    if(max_health <= damage and increase != 0) {
      cout << -1 << "\n";
      return 0;
    }
    H.push_back(hero(max_health, start_health, regen));
  }
  for(int i=0; i<m; i++) {
    int tim, en, health;
    cin >> tim >> en >> health;
    H[en-1].changes.emplace_back(tim, health);
  }
  map <int, int> plus, minus;
  set <int> times;
  for(int i=0; i<n; i++) {
    for(auto ele : H[i].killable_periods()) {
      plus[ele.first]++;
      minus[ele.second]++;
      times.insert(ele.first);
      times.insert(ele.second);
    }
  }
  int killable = 0;
  ll res = 0;
  for(auto t : times) {
    killable += plus[t];
    res = max(res, 1LL * killable * (bounty + 1LL * t * increase));
    if(t > 2e9 and killable > 0 and increase != 0) {
      cout << -1 << "\n";
      return 0;
    }
    killable -= minus[t];
  }
  cout << res << "\n";
  return 0;
}