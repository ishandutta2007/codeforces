#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<20;
int sum[nax*2];

void add(int i, int v) {
  for (i += nax; i; i >>= 1)
    sum[i] += v;
}
int findK(int k) {
  int i = 1;
  while (i < nax) {
    if (sum[i*2] <= k)
      k -= sum[i*2], i = i*2+1;
    else i *= 2;
  }
  return i-nax;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    add(a, 1);
  }
  while (q--) {
    int k;
    cin >> k;
    if (k < 0) {
      add(findK(-k-1), -1);
    } else {
      add(k, 1);
    }
  }
  if (sum[1] == 0) cout << 0 << endl;
  else cout << findK(0) << endl;
}