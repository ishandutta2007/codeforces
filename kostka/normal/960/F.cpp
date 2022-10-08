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

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  set <pii> S[n];
  for(int i=0; i<n; i++) S[i].emplace(-1e9, 0);
  while(m--) {
    int a, b, w;
    cin >> a >> b >> w;
    a--; b--;
    auto it = prev(S[a].lower_bound({w, -1}));
    int cura = (*it).y + 1;
    auto jt = prev(S[b].lower_bound({w, -1}));
    int curb = (*jt).y + 1;
    if(curb <= cura) {
      auto kt = next(S[b].emplace(w, cura).x);
      vector <pii> to_remove;
      while(kt != S[b].end() and (*kt).y <= cura) {
        to_remove.push_back(*kt);
        kt = next(kt);
      }
      for(auto p : to_remove) S[b].erase(p);
    }
  }
  int ret = 0;
  for(int i=0; i<n; i++) for(auto s : S[i]) ret = max(ret, s.y);
  cout << ret << "\n";
  return 0;
}