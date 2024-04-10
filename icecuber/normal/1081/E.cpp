#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll y[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int last = 0;
  for (int i = 0; i < n/2; i++) {
    int x, besta, bestb = 1e9;
    cin >> x;
    for (int j = 1; j*j < x; j++) {
      if (x%j) continue;
      int a = j, b = x/j;
      if (a > b) swap(a,b);
      int ca = a;
      a = b-ca;
      b = b+ca;
      if (a&1) continue;
      a >>= 1, b >>= 1;
      if (a > last && b < bestb) besta = a, bestb = b;
    }
    if (bestb == 1e9) {
      cout << "No" << endl;
      return 0;
    }

    y[i*2] = 1ll*besta*besta-1ll*last*last;
    y[i*2+1] = x;
    last = bestb;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
    cout << y[i] << ' ';
  cout << endl;
}