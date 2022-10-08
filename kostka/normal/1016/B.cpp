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
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  string x, y;
  cin >> x >> y;
  vi vis = {0};
  for(int i=0; i<=a-b; i++) {
    if(x.substr(i, b) == y) vis.push_back(1);
    else vis.push_back(0);
  }
  for(int i=1; i<=a-b+1; i++) vis[i] += vis[i-1];
  while(c--) {
    int p, q;
    cin >> p >> q;
    if(q-p+1 < b) cout << 0 << "\n";
    else cout << vis[q-b+1] - vis[p-1] << "\n";
  }
  return 0;
}