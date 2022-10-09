// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];
vector<pair<int, int>> v;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;

  for (int i=2; i<=n; i++) {
    cout << "XOR 1 " << i << "\n" << flush;
    cin >> a[i];
  }

  for (int i=1; i<=n; i++) {
    v.emplace_back(a[i], i);
  }

  sort(begin(v), end(v));
  int p=-1, q=-1;
  for (int i=0; i<n-1; i++) {
    if (v[i].first == v[i+1].first) {
      p = v[i].second;
      q = v[i+1].second;
    }
  }

  if (p == -1) {
    for (int i=1; i<=n; i++) {
      if (a[i] == 0) {
        p = i;
      } else if (a[i] == n-1) {
        q = i;
      }
    }

    int r = 1;
    while (r == p || r == q) r++;

    cout << "AND " << r << ' ' << p << '\n' << flush;
    int x;
    cin >> x;

    cout << "AND " << r << ' ' << q << '\n' << flush;
    int y;
    cin >> y;

    int z = x ^ y;

    z ^= a[r];

    for (int i=1; i<=n; i++) {
      a[i] ^= z;
    }

  } else {
    cout << "OR " << p << ' ' << q << '\n' << flush;
    int x;
    cin >> x;
    x ^= a[p];
    for (int i=1; i<=n; i++) {
      a[i] ^= x;
    }
  }

  cout << "! ";
  for (int i=1; i<=n; i++) {
    cout << a[i] << " \n"[i == n];
  }
  cout << flush;
}

/*
a b c a^b a^c ab b+c
0 0 0   0   0  0   0
0 0 1   0   1  0   1
0 1 0   1   0  0   1
0 1 1   1   1  0   1
1 0 0   1   1  0   0
1 0 1   1   0  0   1
1 1 0   0   1  1   1
1 1 1   0   0  1   1




*/