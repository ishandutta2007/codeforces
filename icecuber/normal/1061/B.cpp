#include <bits/stdc++.h>
using namespace std;

int a[100000];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int good = 1;
  long long sum = 0;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= good) good++;
    sum += a[i];
    ma = max(ma, a[i]);
  }
  cout << sum-(n+ma-good)-1 << endl;
}