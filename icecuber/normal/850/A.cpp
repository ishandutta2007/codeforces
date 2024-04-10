#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
vi operator-(vi a, vi b) {
  vi r(5);
  for (int i = 0; i < 5; i++)
    r[i] = a[i]-b[i];
  return r;
}
int operator*(vi a, vi b) {
  int r = 0;
  for (int i = 0; i < 5; i++)
    r += a[i]*b[i];
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n > 100) {
    cout << 0 << endl;
  } else {
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
      vector<int> p(5);
      for(int&j : p) cin >> j;
      v[i] = p;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int good = 1;
      for (int j = 0; j < n; j++) {
	for (int k = 0; k < j; k++) {
	  if ((v[i]-v[j])*(v[i]-v[k]) > 0) good = 0;
	}
      }
      if (good) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
  }
}