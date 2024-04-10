// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<vector<int>, int> mp;
map<vector<int>, pair<int, int>> mv;

int solve(vector<int> a) {
  int n = a.size();
  if (mp.count(a)) {
    return mp[a];
  }

  int& sol = mp[a];

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i != j && a[j] == i) {
        auto b = a;
        swap(b[i], b[j]);
        int cand = solve(b) + (i-j)*(i-j);
        if (cand > sol) {
          sol = cand;
          mv[a] = {i, j};
        }
      }
    }
  }

  return sol;
}

void test() {
  int n, mx = 0;
  cin >> n;
  vector<int> a(n), aa;
  iota(begin(a), end(a), 0);

  do {
    int v = solve(a);
    mx = max(mx, v);
  } while (next_permutation(begin(a), end(a)));

  cout << mx << '\n';

  for (auto [k, v] : mp) {
    if (v == mx) {
      for (int x : k) {
        cout << x+1 << ' ';
      }
      cout << '\n';
      auto b = k;
      while (!is_sorted(begin(b), end(b))) {
        auto [i, j] = mv[b];
        cout << i+1 << ' ' << j+1 << '\n';
        swap(b[i], b[j]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n % 2 == 0) {
      vector<int> a(n);

      a[0] = n/2+1;
      for (int i=1; i<n/2; i++) {
        a[i] = i;
      }

      for (int i=n/2; i<n-1; i++) {
        a[i] = i+2;
      }
      a[n-1] = n/2;

      ll val = 0;
      for (int x=n/2; x<=n-2; x++) {
        val += 2ll*x*x;
      }
      val += (n-1ll)*(n-1);

      cout << val << '\n';
      for (int x : a) {
        cout << x << ' ';
      }
      cout << '\n';
      cout << n-1 << '\n';
      for (int x=n/2; x>=2; x--) {
        cout << x << ' ' << n << '\n';
      }
      for (int x=n/2+1; x<=n-1; x++) {
        cout << x << " 1\n";
      }
      cout << "1 " << n << '\n';
    } else {
      vector<int> a(n);

      a[0] = n/2+1;
      for (int i=1; i<n/2; i++) {
        a[i] = i;
      }

      for (int i=n/2; i<n-1; i++) {
        a[i] = i+2;
      }
      a[n-1] = n/2;

      // calc val?
      ll val = 0;
      for (int x=n/2; x<=n-2; x++) {
        val += 2ll*x*x;
      }
      val -= (n/2ll)*(n/2);
      val += (n-1ll)*(n-1);

      cout << val << '\n';
      for (int x : a) {
        cout << x << ' ';
      }
      cout << '\n';
      cout << n-1 << '\n';
      for (int x=n/2; x>=2; x--) {
        cout << x << ' ' << n << '\n';
      }
      for (int x=n/2+1; x<=n-1; x++) {
        cout << x << " 1\n";
      }
      cout << "1 " << n << '\n';
    }
  }
}