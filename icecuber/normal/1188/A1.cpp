#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int deg[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}