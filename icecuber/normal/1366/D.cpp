#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e7+10;
int isprime[nax];
int fac[nax];

int main() {
  for (int i = 2; i < nax; i++) {
    if (fac[i]) continue;
    for (int j = i; j < nax; j += i) {
      fac[j] = i;
    }
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> d(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int p = fac[a];
    if (!p) {
      d[i] = {-1,-1};
    } else {
      int x = 1;
      while (a%p == 0) a /= p, x *= p;
      int y = a;
      if (x > 1 && y > 1)
	d[i] = {x,y};
      else
	d[i] = {-1,-1};
    }
  }
  for (int i = 0; i < n; i++)
    cout << d[i][0] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << d[i][1] << ' ';
  cout << endl;
}