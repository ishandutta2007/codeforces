#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,int> mem;
int f(int m) {
  m -= (m&1);
  if (!m) return 0;

  if (!mem.count(m)) {
    vector<int> reach;
    for (int x = 1; m>>x; x++) {
      reach.push_back(f(m&(1<<x)-1 | m>>x));
    }
    int r = 0;
    while (count(reach.begin(), reach.end(), r)) r++;
    mem[m] = r;
  }
  return mem[m];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,vector<int>> m;
  for (int i = 0; i < n; i++) {
    map<int,int> fac;
    int a;
    cin >> a;
    for (int d = 2; d*d <= a; d++) {
      while (a%d == 0) {
	++fac[d];
	a /= d;
      }
    }
    if (a > 1) ++fac[a];
    for (auto [d, c] : fac)
      m[d].push_back(c);
  }
  int xor_sum = 0;
  for (auto [d,v] : m) {
    int mask = 0;
    for (int i : v)
      mask |= 1<<i;
    xor_sum ^= f(mask);
  }
  cout << (xor_sum == 0 ? "Arpa" : "Mojtaba") << endl;
}