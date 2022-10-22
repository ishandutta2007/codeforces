#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int c[3] = {};
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    c[v]++;
  }
  if (c[2]) cout << 2 << ' ', c[2]--;
  if (c[1]) cout << 1 << ' ', c[1]--;
  for (int i = 0; i < c[1]/2; i++)
    cout << 1 << ' ' << 1 << ' ';
  for (int i = 0; i < c[2]; i++)
    cout << 2 << ' ';
  if (c[1]%2) cout << 1 << ' ';
  cout << endl;
}