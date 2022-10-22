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
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31};
    vector<int> ans(n);
    map<int,int> comp;
    int cc = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for (int p : prime)
	if (a%p == 0) ans[i] = p;
      if (!comp.count(ans[i])) comp[ans[i]] = ++cc;
      ans[i];
    }
    cout << cc << endl;
    for (int a : ans) cout << comp[a] << ' ';
    cout << endl;
  }
}