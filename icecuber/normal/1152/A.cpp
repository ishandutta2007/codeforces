#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a[2] = {}, b[2] = {};
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[v%2]++;
  }
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    b[v%2]++;
  }
  cout << min(a[0],b[1])+min(a[1],b[0]) << endl;
}