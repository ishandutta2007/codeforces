#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w[500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> w[i];
  vector<int> v(n);
  int vlen = 0;
  int ans = 0;
  while (m--) {
    int b;
    cin >> b;
    b--;
    cout << endl;
    int j = 0;
    while (j < vlen && v[j] != b) ans += w[v[j]], j++;
    if (j == vlen) v[vlen++] = b;
    for (int i = j; i; i--)
      swap(v[i],v[i-1]);
    //for (int i = 0; i < vlen; i++) cout << v[i]+1 << ' ';
    //cout << endl;
  }
  cout << ans << endl;
}