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
#define ALL(X) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  multiset <int> M;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    M.insert(x);
  }
  int ret = 0;
  pair <int, bool> pre = {-1, false};
  for(auto x : M) {
    if(x == pre.x) {
      if(pre.y == false) ret++;
      continue;
    }
    bool ok = false;
    for(int i=0; i<31; i++) {
      int w = (1<<i) - x;
      if(w == x and M.count(w) >= 2) {
        ok = true;
        break;
      }
      if(w != x and M.count(w) >= 1) {
        ok = true;
        break;
      }
    }
    pre = {x, ok};
    if(!ok) ret++;
  }
  cout << ret << "\n";
  return 0;
}