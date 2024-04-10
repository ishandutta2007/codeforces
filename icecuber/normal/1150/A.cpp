#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  int a = 1e9, b = -1e9;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a = min(a, v);
  }
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    b = max(b, v);
  }
  int k = b > a ? r/a : 0;
  cout << k*(b-a)+r << endl;
}