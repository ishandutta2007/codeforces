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
  string a, b;
  cin >> n;
  cin >> a >> b;
  map <pii, int> M;
  for(int i=0; i<n; i++) {
    M[{a[i],b[i]}] += 1;
  }
  cout << 1LL * M[{'0','0'}] * (M[{'1','0'}] + M[{'1', '1'}]) + 1LL * M[{'1','0'}] * M[{'0','1'}] << "\n";
  return 0;
}