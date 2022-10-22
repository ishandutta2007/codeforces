#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[200000], b[200000];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n/2; i++)
    cin >> b[i];
  a[0] = 0;
  a[n-1] = b[0];
  for (int i = 1; i < n/2; i++) {
    a[i] = max(a[i-1], b[i]-a[n-1-(i-1)]);
    a[n-1-i] = b[i]-a[i];
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
}