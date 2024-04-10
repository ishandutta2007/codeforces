// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[200005], b[200005];

bool moze(int m) {
  for (int i=0; i<n; i++) {
    b[i+1] = b[i] + (a[i] >= m ? 1 : -1);
  }

  int h = 0;
  for (int i=k; i<=n; i++) {
    h = min(h, b[i-k]);
    if (b[i] > h) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int l = 2, r = n, o = 1;

  while (l <= r) {
    int m = (l+r) / 2;
    if (moze(m)) {
      o = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << o << '\n';
}