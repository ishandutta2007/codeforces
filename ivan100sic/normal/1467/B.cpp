// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[300005];
int c[300005], cz;

void uc(int i, int x) {
  if (i < 1 || i > n) return;
  cz -= c[i];
  c[i] = x;
  cz += c[i];
}

int g(int i) {
  return i > 1 && i < n && ((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1]));
}

void ua(int i, int x) {
  a[i] = x;
  for (int j : {i-1, i, i+1}) {
    uc(j, g(j));
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    cz = 0;
    for (int i=1; i<=n; i++) {
      a[i] = c[i] = 0;
    }

    int sol = 123123123;

    for (int i=1; i<=n; i++) {
      int x;
      cin >> x;
      ua(i, x);
    }

    for (int i=1; i<=n; i++) {
      set<int> v;
      for (int j=i-1; j<=i+1; j++) {
        for (int d=-1; d<=1; d++) {
          v.insert(a[j] + d);
        }
      }
      for (int x : v) {
        int t = a[i];
        ua(i, x);
        sol = min(sol, cz);
        ua(i, t);
      }
    }

    cout << sol << '\n';
  }
}