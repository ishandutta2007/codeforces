#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int cnt = 0, cp = n;
  while (cp > 1) cnt++, cp = (cp+k-1)/k;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int a = i, b = j;
      int c = 0;
      while (a != b) a /= k, b /= k, c++;
      cout << c << ' ';
    }
  }
  cout << endl;
}