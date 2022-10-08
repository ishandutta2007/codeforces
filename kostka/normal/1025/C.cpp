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
  string x;
  cin >> x;
  int ret = 0;
  int cnt = 1;
  for(int i=1; i<2*SZ(x); i++) {
    if(x[i%SZ(x)] != x[(i-1)%SZ(x)]) cnt++;
    else cnt = 1;
    ret = max(ret, min(SZ(x), cnt));
  }
  cout << ret << "\n";
  return 0;
}