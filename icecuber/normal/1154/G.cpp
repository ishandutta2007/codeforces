#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 1e7+1;
int has[m];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 1e18, ansa = 0, ansb = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (has[a]) {
      if (a < ans) {
	ans = a;
	ansa = i+1;
	ansb = has[a];
      }
    } else
      has[a] = i+1;
  }
  for (int i = 1; i < m; i++) {
    int a = 1e9, b = 1e9, ai, bi;
    for (int j = i; j < m; j += i)
      if (has[j]) {
	if (j < a) b = a, bi = ai, a = j, ai = has[j];
	else if (j < b) b = j, bi = has[j];
      }
    ll v = 1ll*a/i*b;
    if (b < 1e9 && v < ans) {
      ans = v;
      ansa = ai;
      ansb = bi;
    }
  }
  if (ansa > ansb) swap(ansa,ansb);
  cout << ansa << ' ' << ansb << endl;
}