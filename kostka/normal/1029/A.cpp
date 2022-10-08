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
  int n, k;
  cin >> n >> k;
  string x;
  cin >> x;
  string res = x;
  for(int i=n-1; i>=0; i--) if(x.substr(n-i, i) == x.substr(0, i)) {
    for(int j=1; j<k; j++) x += x.substr(i, n-i);
    break;
  }
  cout << x << "\n";
  return 0;
}