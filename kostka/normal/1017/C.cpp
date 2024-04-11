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
  int n;
  cin >> n;
  int w = -1, ilo = 1e9;
  for(int i=1; i<=n; i++) {
    int res = (n + i - 1) / i + i;
    if(res < ilo) {
      ilo = res;
      w = i;
    }
  }
  for(int i=n; i>=1; i-=w) {
    for(int j=max(1,i-w+1); j<=i; j++) cout << j << " ";
  }
  cout << "\n";
  return 0;
}