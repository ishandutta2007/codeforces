#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  for (int l = s.size(); l; l--) {
    for (int i = 0; i+l <= s.size(); i++) {
      string p = s.substr(i,l);
      int occ = 0;
      for (int k = 0; k+l <= s.size(); k++)
	if (s.substr(k,l)==p) occ++;
      if (occ >= 2) {
	cout << l << endl;
	return 0;
      }
    }
  }
  cout << 0 << endl;
}