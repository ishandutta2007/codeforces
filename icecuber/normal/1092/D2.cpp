#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int x[200001], y[200001], dlen;
int check(int*a, int n) {
  dlen = 0;
  x[dlen] = -1;
  y[dlen++] = 2e9;
  for (int i = 0; i < n; i++) {
    while (a[i] > y[dlen-1]) dlen--;
    if ((i-x[dlen-1])%2==0) return 0;
    x[dlen] = i;
    y[dlen++] = a[i];
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ok = check(a,n);
  reverse(a,a+n);
  ok &= check(a,n);
  cout << (ok ? "YES" : "NO") << endl;
}