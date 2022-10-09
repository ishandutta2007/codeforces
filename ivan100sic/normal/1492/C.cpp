// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> cc(string a, string b) {
  vector<int> c;
  int j = 0;
  for (int i=0; i<(int)a.size(); i++) {
    if (j < (int)b.size() && a[i] == b[j]) {
      j++;
      c.push_back(i);
    }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;

  string a, b;
  cin >> a >> b;

  auto p = cc(a, b);
  reverse(begin(a), end(a));
  reverse(begin(b), end(b));
  auto q = cc(a, b);

  int z = 0;
  for (int i=1; i<m; i++) {
    z = max(z, n - 1 - p[i-1] - q[m-i-1]);
  }

  cout << z << '\n';
}