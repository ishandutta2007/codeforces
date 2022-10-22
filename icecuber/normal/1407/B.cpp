#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int g = 0;
    for (int i = 0; i < n; i++) {
      int besti = 0;
      for (int j = 0; j < a.size(); j++) {
	if (gcd(g,a[j]) > gcd(g,a[besti])) besti = j;
      }
      g = gcd(g, a[besti]);
      cout << a[besti] << ' ';
      a.erase(a.begin()+besti);
    }
    cout << endl;
  }
}