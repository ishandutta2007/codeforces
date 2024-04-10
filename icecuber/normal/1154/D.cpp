#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, b0, a0, b, a;
  cin >> n >> b0 >> a0;
  a = a0, b = b0;
  for (int i = 0; i < n; i++) {
    if (!a && !b) {
      cout << i << endl;
      return 0;
    }
    int s;
    cin >> s;
    if (s && b && a < a0 || !a)
      b--, a += s;
    else
      a--;
  }
  cout << n << endl;
}