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
  string s;
  cin >> s;
  vector <pii> las = {{0, 0}, {-1, -1}, {-1, -1}};
  int r = 0;
  int ret = 0;
  for(int i=0; i<SZ(s); i++) {
    r += s[i] - '0';
    r %= 3;
    if(las[r].x != -1) ret = max(ret, las[r].y + 1);
    las[r] = {i, ret};
  }
  cout << ret << "\n";
  return 0;
}