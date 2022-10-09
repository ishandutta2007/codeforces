// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> poz(vector<int> a) {
  vector<int> b;
  copy_if(begin(a), end(a), back_inserter(b), [](int x) { return x > 0; });
  return b;
}

int resi(vector<int> a, vector<int> b) {
  sort(begin(a), end(a)); // kutije
  sort(begin(b), end(b)); // targeti

  int m = b.size();
  int z = 0;

  vector<int> suff_match(m+1);
  for (int i=m-1; i>=0; i--) {
    suff_match[i] = suff_match[i+1] + binary_search(begin(a), end(a), b[i]);
  }

  for (int i=0; i<m; i++) { // po targetima
    int k = upper_bound(begin(a), end(a), b[i]) - begin(a); // broj kutija pre targeta
    if (k == 0) continue;
    int c = begin(b) + i - lower_bound(begin(b), end(b), b[i]-k+1) + 1;
    c += suff_match[i+1];
    z = max(z, c);
  }

  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int sol = 0;
    sol += resi(poz(a), poz(b));
    for (int& x : a) x = -x;
    for (int& x : b) x = -x;
    sol += resi(poz(a), poz(b));

    cout << sol << '\n';
  }
}