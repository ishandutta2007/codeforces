#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int d[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], d[i] = 1e9;
  int lastzero = -1e9;
  for (int i = 0; i < n; i++) {
    if (!a[i]) lastzero = i;
    d[i] = min(d[i], i-lastzero);
  }
  lastzero = 1e9;
  for (int i = n-1; i >= 0; i--) {
    if (!a[i]) lastzero = i;
    d[i] = min(d[i], lastzero-i);
  }
  for (int i = 0; i < n; i++)
    cout << d[i] << ' ';
  cout << endl;
}