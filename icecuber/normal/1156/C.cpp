#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, z;
  cin >> n >> z;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x+n);
  int pass = 0, fail = n/2+1;
  while (fail-pass > 1) {
    int mid = pass+fail>>1, ok = 1;
    for (int i = 0; i < mid; i++)
      if (x[n-mid+i]-x[i] < z) ok = 0;
    if (ok) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}