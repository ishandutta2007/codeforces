#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[200000], par[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  fill_n(par, n, -1);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
    assert(f[i] != i);
    if (f[i] != -1)
      par[f[i]] = i;
  }
  int a = -1, b = -1;
  for (int i = 0; i < n; i++) {
    if (f[i] == -1 && par[i] != -1) {
      int p = i;
      while (par[p] != -1)
	p = par[p];
      f[i] = p;
      par[p] = i;
      a = i, b = p;
    }
  }
  for (int i = 0; i < n; i++) {
    if (f[i] == -1) {
      if (a == -1 && b == -1) {
	a = i, b = i;
      }
      f[a] = i;
      f[i] = b;
      a = i;
    }
  }
  for (int i = 0; i < n; i++)
    cout << f[i]+1 << ' ';
  cout << endl;
}